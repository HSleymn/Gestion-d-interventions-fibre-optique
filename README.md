# Gestion d'interventions fibre optique

Ce projet est une application en langage C pour la gestion des interventions liées à la fibre optique. Il permet de gérer les inscriptions des entreprises, la publication de missions, l'acceptation de missions, la sous-traitance, et la génération de rapports.

## Fonctionnalités actuelles

- **Inscription** : Permet aux entreprises de s'inscrire avec un rôle spécifique (OP, AG, IN).
- **Publication de missions** : Les entreprises peuvent publier des missions avec un nom et une rémunération.
- **Consultation des missions** : Affiche la liste des missions disponibles.
- **Détail d'une mission** : Affiche les détails d'une mission spécifique.
- **Acceptation de missions** : Les entreprises peuvent accepter des missions disponibles.
- **Sous-traitance** : Permet de sous-traiter une mission à une autre entreprise.
- **Rapport** : Enregistre un rapport pour une mission terminée.
- **Récapitulatif** : Affiche un récapitulatif des missions pour une entreprise donnée.

## Fonctionnalités à développer

Voici une liste des fonctionnalités sur lesquelles je vais travailler prochainement :

1. **Gestion des échecs** :
   - Implémenter un système pour suivre les échecs des entreprises dans l'exécution des missions.
   - Limiter l'acceptation de nouvelles missions pour les entreprises ayant trop d'échecs.

2. **Validation des missions sous-traitées** :
   - Vérifier que le nombre de sous-traitances ne dépasse pas un certain seuil (par exemple, 5 niveaux de sous-traitance).
   - Assurer que les missions sous-traitées sont correctement enregistrées et suivies.

3. **Amélioration des rapports** :
   - Ajouter des codes de retour détaillés pour les missions terminées (succès, échec partiel, échec total, etc.).
   - Générer des rapports plus complets incluant les détails des sous-traitances.

4. **Interface utilisateur** :
   - Développer une interface en ligne de commande plus conviviale.
   - Ajouter des options de filtrage et de tri pour les missions.

5. **Tests et validation** :
   - Écrire des tests unitaires pour chaque fonctionnalité.
   - Valider les entrées utilisateur pour éviter les erreurs.

6. **Documentation** :
   - Ajouter des commentaires détaillés dans le code.
   - Créer un guide utilisateur pour expliquer comment utiliser l'application.

## Structure du projet

Le projet est structuré comme suit :

hsleymn-gestion-d-interventions-fibre-optique/
└── main.c
Copy


- **`main.c`** : Contient le code source principal de l'application.

## Installation

Pour compiler et exécuter ce projet localement, suivez les étapes suivantes :

1. Clonez le dépôt :
   ```bash
   git clone https://github.com/HSleymn/Gestion-d-interventions-fibre-optique.git

    Accédez au répertoire du projet :
    bash
    Copy

    cd Gestion-d-interventions-fibre-optique

    Compilez le programme :
    bash
    Copy

    gcc main.c -o gestion_interventions

    Exécutez le programme :
    bash
    Copy

    ./gestion_interventions

# Utilisation

Une fois le programme lancé, vous pouvez interagir avec lui en entrant les commandes suivantes :

    Inscription : inscription <role> <nom>

    Publication de mission : mission <id_entreprise> <nom_mission> <remuneration>

    Consultation des missions : consultation

    Détail d'une mission : detail <id_mission>

    Acceptation de mission : acceptation <id_entreprise> <id_mission>

    Sous-traitance : sous-traitance <id_entreprise> <id_mission> <remuneration>

    Rapport : rapport <id_mission> <code_retour>

    Récapitulatif : recapitulatif <id_entreprise>

    Quitter : exit

## Contribution

Les contributions sont les bienvenues ! Si vous souhaitez contribuer à ce projet, veuillez suivre les étapes suivantes :

    Forkez le projet.

    Créez une branche pour votre fonctionnalité (git checkout -b feature/NouvelleFonctionnalité).

    Committez vos changements (git commit -m 'Ajout d'une nouvelle fonctionnalité').

    Pushez vers la branche (git push origin feature/NouvelleFonctionnalité).

    Ouvrez une Pull Request.

## Auteur

    HADJ MESSAOUD Souleymane - HSleymn

## Licence  

Ce projet est sous licence MIT.
