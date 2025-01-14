# **RequêteSQL : Application Qt pour Gestion de Base de Données MySQL**

Ce projet est une application graphique interactive développée avec **Qt** pour se connecter à une base de données MySQL, récupérer et afficher les données d'une table dans un tableau, et permettre leur gestion.

---

## **Structure du projet**

### **1. Fichiers du projet**

- **`requeteSQL.pro`** :  
  Fichier de configuration du projet Qt. Il définit les modules utilisés (Core, GUI, SQL), les fichiers source, les fichiers d'en-tête, ainsi que les formulaires pour l'interface graphique.

- **`main.cpp`** :  
  Le point d'entrée de l'application. Ce fichier :
  - Initialise la connexion à la base de données MySQL.
  - Crée un tableau graphique interactif (*QTableWidget*) pour afficher les données.
  - Effectue une requête SQL pour récupérer les informations de la table `jeu` et les insère dans le tableau.

- **`widget.h` et `widget.cpp`** :  
  Définit et implémente la classe `Widget`, qui représente une fenêtre ou un composant de l'interface utilisateur. Ce fichier est généré par **Qt Designer** et est destiné à des extensions futures.

- **`widget.ui`** :  
  Fichier de conception de l'interface graphique créé avec **Qt Designer**. Il contient la disposition des widgets dans la fenêtre.

- **`jeu.sql`** :  
  Un fichier SQL contenant la structure et les données initiales de la table `jeu`. Il est fourni pour simplifier la création de la base de données nécessaire au projet.

---

## **Fonctionnalités**

### **Interface graphique dynamique**
- **Affichage des données dans un tableau** :  
  Les données de la table `jeu` (colonnes `Nom`, `Club`, et `Note`) sont affichées dans un **QTableWidget**.  
  Le tableau est redimensionné automatiquement pour afficher toutes les données récupérées.

- **Connexion sécurisée à MySQL** :  
  La connexion utilise les paramètres suivants :
  - **Hôte** : `127.0.0.1` (local)
  - **Port** : `3306` (par défaut)
  - **Base de données** : `test`
  - **Utilisateur** : `huseyin`
  - **Mot de passe** : `jondow`

---

## **Pré-requis**

### **Environnement de développement**
- **Qt Framework** (version 5 ou supérieure).
- **MySQL** installé localement ou accessible via réseau.
- Un compilateur prenant en charge **C++17**.

---

## **Importer un fichier SQL dans une base de données MySQL**

Pour utiliser ce projet, vous devez importer le fichier `jeu.sql` dans votre base de données MySQL. Suivez les étapes ci-dessous :

### **Étapes d'importation**
1. **Vérifiez que MySQL est installé et en cours d'exécution** :  
   Assurez-vous que le serveur MySQL est démarré sur votre machine.

2. **Ouvrez un terminal ou une invite de commande** :  
   Accédez à l'emplacement où se trouve le fichier `jeu.sql`.

3. **Connectez-vous à MySQL** :  
   Exécutez la commande suivante pour accéder à MySQL avec votre utilisateur :

   ```bash
   mysql -u root -p
   ```

   Remplacez `root` par votre nom d'utilisateur MySQL si nécessaire. Saisissez votre mot de passe MySQL lorsqu'il est demandé.

4. **Créer la base de données (si elle n'existe pas déjà)** :  
   Une fois connecté à MySQL, créez la base de données nommée `test` avec la commande suivante :

   ```sql
   CREATE DATABASE test;
   ```

5. **Importer le fichier SQL** :  
   Quittez MySQL en tapant `exit`, puis utilisez la commande suivante pour importer le fichier SQL dans la base de données :

   ```bash
   mysql -u root -p test < jeu.sql
   ```

   Ici, `test` est le nom de la base de données dans laquelle le fichier `jeu.sql` sera importé.

6. **Vérifiez les données** :  
   Connectez-vous à MySQL et utilisez la base `test` :

   ```bash
   USE test;
   SELECT * FROM jeu;
   ```

   Vous devriez voir les données du fichier SQL.

---

## **Compilation et exécution**

1. **Cloner le projet** :  
   Clonez ou téléchargez les fichiers du projet.

2. **Ouvrir avec Qt Creator** :  
   Ouvrez le fichier `requeteSQL.pro` dans Qt Creator.

3. **compiler** :  
   Compilez et exécutez.

4. **Tester l'application** :  
   Une fenêtre s'ouvrira avec un tableau contenant les données de la table **`jeu`**.

---

## **Améliorations possibles**

- Ajouter la possibilité de modifier directement les données du tableau et de les enregistrer dans la base de données.
- Ajouter des contrôles pour insérer ou supprimer des lignes via l'interface graphique.
- Gérer les erreurs de connexion avec des messages d'erreur détaillés.
- Implémenter des tests unitaires pour les fonctionnalités critiques.
