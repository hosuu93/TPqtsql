#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQuery>
#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    w.resize(600, 400);  // Redimensionne la fenêtre pour avoir assez d'espace pour le tableau

    // Crée un QTableWidget pour afficher les résultats
    QTableWidget *tableWidget = new QTableWidget(&w);
    tableWidget->setGeometry(10, 10, 580, 380);  // Position et taille du tableau
    tableWidget->setColumnCount(3);  // Nombre de colonnes (3 : Nom, Club, Note)
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Nom" << "Club" << "Note");  // En-têtes de colonnes

    // Connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("test");  // Nom de la base de données
    db.setHostName("127.0.0.1"); // Adresse de l'hôte
    db.setPort(3306);            // Port (3306 par défaut pour MySQL)
    db.setUserName("huseyin");   // Nom d'utilisateur
    db.setPassword("jondow");    // Mot de passe

    if (db.open()) {
        qDebug() << "Vous êtes maintenant connecté à " << db.hostName();

        // Requête SQL pour récupérer les données
        QSqlQuery query;
        query.exec("SELECT * FROM `jeu`");

        int row = 0;  // Compteur pour les lignes dans QTableWidget
        while (query.next()) {
            QString prenom = query.value(1).toString();  // Récupère le Nom (colonne 1)
            QString club = query.value(2).toString();    // Récupère le Club (colonne 2)
            int note = query.value(3).toInt();           // Récupère la Note (colonne 3)

            // Ajouter une nouvelle ligne dans le tableau
            tableWidget->insertRow(row);

            // Ajouter les données dans la ligne et les colonnes
            tableWidget->setItem(row, 0, new QTableWidgetItem(prenom));
            tableWidget->setItem(row, 1, new QTableWidgetItem(club));
            tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(note)));  // Convertir 'note' en QString

            row++;  // Passer à la ligne suivante
            qDebug() << prenom << club << note;
        }
        qDebug() << "Requête ok ! :)";
    } else {
        qDebug() << "La connexion a échoué, désolé";
    }
    // Afficher la fenêtre principale
    w.show();
    return a.exec();
}
