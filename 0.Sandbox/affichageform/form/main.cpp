#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget fenetre;

    // Création du layout de formulaire et de ses widgets

    QLineEdit *nom = new QLineEdit;
    QLineEdit *prenom = new QLineEdit;
    QLineEdit *age = new QLineEdit;

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Votre &nom", nom);
    formLayout->addRow("Votre &prénom", prenom);
    formLayout->addRow("Votre â&ge", age);

    // Création du layout principal de la fenêtre (vertical)

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
layoutPrincipal->addLayout(formLayout); // Ajout du layout de formulaire

    QPushButton *boutonQuitter = new QPushButton("Quitter");
    QWidget::connect(boutonQuitter, SIGNAL(clicked()), &app, SLOT(quit()));
layoutPrincipal->addWidget(boutonQuitter); // Ajout du bouton

    fenetre.setLayout(layoutPrincipal);

    fenetre.show();

    return app.exec();
}
