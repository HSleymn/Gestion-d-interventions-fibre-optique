/*------------------------------ENTETE------------------------------*/

#include <stdio.h>
#include <string.h>
#include <signal.h>
#pragma warning(disable:4996)

enum { NB_CHAR_MAX = 30, NB_INSCR_MAX = 50, NB_MISS_MAX = 500, NB_NV_SS_TRAIT = 5, ID_VIDE = 0};

typedef struct {
	char role[NB_CHAR_MAX];
	char nom[NB_CHAR_MAX];
}Inscription;

typedef struct {
	enum etat{TERMINEE, A_REALISER, NON_ATTRIBUEE, ATTRIBUEE, REALISEE};
	unsigned int id; //identifiant de la mission
	char nom[NB_CHAR_MAX]; // NOM
	double remuneration; //ARGENT
	unsigned int attribution; //identifiant de l'entreprise qui accepte
	unsigned int entreprise; //identifiant de l'entreprise qui publie la mission
	unsigned int compteur_echec;
}Mission;

/*--------------------------------C1--------------------------------*/

void inscription(Inscription* tab) {
	unsigned int i = 0, valide = 1;
	char role_tmp[NB_CHAR_MAX];
	char nom_tmp[NB_CHAR_MAX];
	scanf("%s %s", role_tmp, nom_tmp);
		if ((strcmp(role_tmp, "OP") != 0) && (strcmp(role_tmp, "AG") != 0) && (strcmp(role_tmp, "IN") != 0)) {
			printf("Role incorrect\n");
			valide = 0;
		}
		while ((i < NB_INSCR_MAX) && strcmp(tab[i].nom, "\0")!=0) {
			if ((strcmp(tab[i].nom, nom_tmp))==0) {
				printf("Nom incorrect\n");
				valide = 0;
				break;
			}
			i++;
		}
		if (valide == 1) {
			strcpy(tab[i].nom, nom_tmp);
			strcpy(tab[i].role, role_tmp);
			printf("Inscription realisee (%u)\n", i+1);
		}
}

/*--------------------------------C2--------------------------------*/

void mission(Mission* tab_missions, Inscription* tab_inscr) {
	unsigned int id_tmp, valide = 0, i = 0;
	char nom_tmp[NB_CHAR_MAX];
	double remuneration_tmp;
	scanf("%u %s %lf", &id_tmp, nom_tmp, &remuneration_tmp);
	if (remuneration_tmp < 0) {
		printf("Remuneration incorrecte\n");
	}
	else {
		if (strcmp(tab_inscr[id_tmp - 1].role, "OP") == 0) {
			while ((i < NB_MISS_MAX) && (tab_missions[i].id != 0)) {
				i++;
			}
			tab_missions[i].id = id_tmp;
			strcpy(tab_missions[i].nom, nom_tmp);
			tab_missions[i].remuneration = remuneration_tmp;
			tab_missions[i].attribution = 0;
			printf("Mission publiee (%u)\n", i + 1);
		}
		else {
			printf("Identifiant incorrect\n");
		}
	}
}

/*--------------------------------C3--------------------------------*/

void consultation(Mission* tab_missions, Inscription* tab_inscr) {
	unsigned int cpt = 0, i = 0;
	while ((i < NB_MISS_MAX) && (tab_missions[i].id != 0)) {
		if (tab_missions[i].attribution == 0) {
			printf("%u %s %s %.2lf ()\n", i+1, tab_missions[i].nom, tab_inscr[tab_missions[i].id].nom, tab_missions[i].remuneration);
			++cpt;
		}
		i++;
	}
	if (cpt == 0) {
		printf("Aucune mission disponible\n");
	}
}

/*--------------------------------C4--------------------------------*/

void detail(Mission* tab_missions, Inscription* tab_inscr) {
	unsigned int id;
	scanf("%u", &id);
	if (tab_missions[id-1].attribution == 0) {
		printf("%u %s %s %.2lf ()\n", id, tab_missions[id-1].nom, tab_inscr[tab_missions[id-1].id].nom, tab_missions[id-1].remuneration);
	}
	else {
		printf("Identifiant incorrect\n");
	}
}

/*--------------------------------C5--------------------------------*/

void acceptation(Mission* tab_missions, Inscription* tab_inscr) {
	unsigned int id1, id2;
	scanf("%u %u", &id1, &id2);
	if (strcmp(tab_inscr[id1-1].role, "OP") == 0) {
		printf("Entreprise incorrecte\n");
	}
	else if ((tab_missions[id2-1].id == 0) || (tab_missions[id2-1].attribution != 0)) {
		printf("Mission incorrecte\n");
	}
	//Impl�menter le cas o� l'entreprise n'a pas �t� responsable d'�checs 
	else {
		tab_missions[id2-1].attribution = 1;
		tab_missions[id2 - 1].entreprise = id1;
		printf("Acceptation enregistree\n");
	}
}

/*--------------------------------C6--------------------------------*/

void sous_traitance(Mission* tab_missions, Inscription* tab_inscr) {
	unsigned int i = 0, id1, id2;
	double remuneration;
	scanf("%u %u %lf", &id1, &id2, &remuneration);
	if (strcmp(tab_inscr[id1 - 1].role, "AG") != 0) {
		printf("Entreprise incorrecte\n");
	}
	else if ((tab_missions[id2 - 1].id == 0) || (tab_missions[id2 - 1].attribution != 0)) {
		printf("Mission incorrecte\n");
	}
	//Impl�menter le nombre de sous-traitance inf�rieur � 5 
	else if (remuneration < 0) {
		printf("Remuneration incorrecte\n");
	}
	else{
		tab_missions[id2 - 1].attribution = 1;
		tab_missions[id2 - 1].entreprise = id1-1;
		while ((i < NB_MISS_MAX) && (tab_missions[i].id != 0)) {
			i++;
		}
		tab_missions[i].id = id2-1;
		tab_missions[i].remuneration = remuneration;
		tab_missions[i].attribution = 0;
		//Est ce qu'on doit ajouter un nom de mission ?
		printf("Sous-traitance enregistree (%u)\n", i+1);
	}
}

/*--------------------------------C7--------------------------------*/

void rapport(Mission* tab_missions, Inscription* tab_inscr) {
	unsigned int i = 0, id1, codeRetour, id2;
	scanf("%u %u", &id1, &codeRetour);
	if (tab_missions[id1-1].attribution != 1) {
		printf("Mission incorrecte\n");
		//Impl�menter le fait que la mission soit a la fin de la chaine de sous traitance
	}
	else if ((id2 != 0) || (id2 != 1) || (id2 != 2) || (id2 != 3)) {
		printf("Code de retour incorrect\n");
	}
	else {
		printf("Rapport enregistre (%u)\n", i + 1);
	}
}

/*--------------------------------C8--------------------------------*/
// passer en parametre le nb de missions crée (et d entreprises)
void recapitulatif(Mission* tab_missions, Inscription* tab_inscr) {
	unsigned int i = 0, id;
	scanf("%u", &id);
	--id;

	printf("point d arret 1 \n");
	if (strcmp(tab_inscr[id].nom, "\0") == 0) {
		printf("Entreprise incorrecte\n");
		return;
	}
	printf("point d arret 2 \n");
	printf("point d arret 3 \n");		
	printf("* non attribuees\n");
	for (i =0; i<NB_MISS_MAX; ++i){
		if (tab_missions[i].attribution == id && tab_missions[i].id != ID_VIDE){
			printf("%u %s %s %lf (%u)\n", tab_missions[i].id, tab_missions[i].nom, tab_inscr[tab_missions[i].attribution].nom, tab_missions[i].remuneration, tab_missions[i].compteur_echec);

		}

	}
	printf("point d arret final \n");	
	//affichage du compte rendu des missions
}

/*----------------------------COMPILATION----------------------------*/

int main() {
	Inscription tab_inscriptions[NB_INSCR_MAX];
	for (int i = 0; i < NB_INSCR_MAX; ++i)
		strcpy(tab_inscriptions[i].nom, "\0");
	Mission tab_missions[NB_MISS_MAX];
	for (int i = 0; i < NB_MISS_MAX; ++i){
		tab_missions[i].id = ID_VIDE;
	}
	while (1==1) {
		char instruction[NB_CHAR_MAX];
		scanf("%s", instruction);
		/*--------------------------------C0--------------------------------*/
		if (strcmp(instruction, "exit") == 0) {
			break;
		}
		else if (strcmp(instruction, "inscription") == 0) {
			inscription(tab_inscriptions);
		}
		else if (strcmp(instruction, "mission") == 0) {
			mission(tab_missions, tab_inscriptions);
		}
		else if (strcmp(instruction, "consultation") == 0) {
			consultation(tab_missions, tab_inscriptions);
		}
		else if (strcmp(instruction, "detail") == 0) {
			detail(tab_missions, tab_inscriptions);
		}
		else if (strcmp(instruction, "acceptation") == 0) {
			acceptation(tab_missions, tab_inscriptions);
		}
		else if (strcmp(instruction, "sous-traitance") == 0) {
			sous_traitance(tab_missions, tab_inscriptions);
		}
		else if (strcmp(instruction, "rapport") == 0) {
			rapport(tab_missions, tab_inscriptions);
		}
		else if (strcmp(instruction, "recapitulatif") == 0) {
			recapitulatif(tab_missions, tab_inscriptions);
		}
	}
	return 0;
}