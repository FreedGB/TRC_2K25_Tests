#include <iostream>
#include <vector>


using namespace std;

class Robot
{
    string nom;
    vector<string> capteurs;
    vector<string> effecteurs;

    public:
        void setNom(string nomDuRobot)
        {
            this->nom = nomDuRobot;
        }
        void setCapteurs(vector<string> &listeCapteurs)
        {
            this->capteurs = listeCapteurs;
        }
        void setEffecteurs(vector<string> &listeEffecteurs)
        {
            this->effecteurs = listeEffecteurs;
        }

        string getNom()
        {
            return this->nom;
        }
        vector<string> getCapteurs()
        {
            return this->capteurs;
        }
        vector<string> getEffecteurs()
        {
            return this->effecteurs;
        }

        void info()
        {
            cout << "\n------ " << this->getNom() << " -----\n";
            
            cout << "Capteurs: ";
            for (string capteur : this->getCapteurs())
            {
                cout << capteur << "  ";
            }

            cout << "\nEffecteurs: ";
            for (string effecteur : this->getEffecteurs())
            {
                cout << effecteur << "  ";
            }

            cout << "\n\n";
        }

        virtual void move(string direction) = 0;
};

class Voiture : public Robot
{
    public:

        Voiture(string nom, vector<string> capteurs, vector<string> roues)
        {
            this->setNom(nom);
            this->setCapteurs(capteurs);
            this->setEffecteurs(roues);
        }

        void move(string direction)
        {
            if (direction == "avant")
            {
                cout << "> " << this->getNom() << " avance:\n";
                cout << this->getEffecteurs()[1] << " tourne dans le sens trigonométrique.\n\n";
            }
            else if (direction == "arriere")
            {
                cout << "> " << this->getNom() << " recule:\n";
                cout << this->getEffecteurs()[1] << " tourne dans le sens anti-trigonométrique.\n\n";
            }
            else if (direction == "gauche")
            {
                cout << "> " << this->getNom() << " tourne à gauche:\n";
                cout << this->getEffecteurs()[0] << " tourne à gauche.\n";
                cout << this->getEffecteurs()[1] << " tourne dans le sens trigonométrique.\n\n";
            }
            else if (direction == "droite")
            {
                cout << "> " << this->getNom() << " tourne à droite:\n";
                cout << this->getEffecteurs()[0] << " tourne à droite.\n";
                cout << this->getEffecteurs()[1] << " tourne dans le sens trigonométrique.\n\n";
            }
            else
            {
                cout << "> " << this->getNom() << " ne bouge pas.\n\n";
            }
        };
};

class Humanoide : public Robot
{
    public:
        Humanoide(string nom, vector<string> capteurs, vector<string> membres)
        {
            this->setNom(nom);
            this->setCapteurs(capteurs);
            this->setEffecteurs(membres);
        }

        void move(string direction)
        {
            if (direction == "avant")
            {
                cout << "> " << this->getNom() << " avance:\n";
                cout << this->getEffecteurs()[0] << " reste fixe.\n";
                cout << this->getEffecteurs()[1] << " avance\n";
                cout << this->getEffecteurs()[2] << " avance.\n\n";
            }
            else if (direction == "arriere")
            {
                cout << "> " << this->getNom() << " recule:\n";
                cout << this->getEffecteurs()[0] << " reste fixe.\n";
                cout << this->getEffecteurs()[1] << " recule\n";
                cout << this->getEffecteurs()[2] << " recule.\n\n";
            }
            else if (direction == "gauche")
            {
                cout << "> " << this->getNom() << " torune à gauche:\n";
                cout << this->getEffecteurs()[2] << " avance.\n";
                cout << this->getEffecteurs()[2] << " glisse à gauche.\n";
                cout << this->getEffecteurs()[0] << " tourne à gauche.\n\n";
            }
            else if (direction == "droite")
            {
                cout << "> " << this->getNom() << " torune à droite:\n";
                cout << this->getEffecteurs()[1] << " avance.\n";
                cout << this->getEffecteurs()[1] << " glisse à droite.\n";
                cout << this->getEffecteurs()[0] << " tourne à droite.\n\n";
            }
            else
            {
                cout << "> " << this->getNom() << " ne bouge pas.\n\n";
            }
        }
};


int main()
{
    cout << "OK.\n";

    
    vector<string> listeCapteurs = {"Ultrason", "Lidar"};
    vector<string> listeRoues = {"Roues avant", "Roues arrière"};
    Voiture v = Voiture("Tesla V1", listeCapteurs, listeRoues);
    v.info();
    v.move("avant");
    v.move("gauche");

    
    vector<string> listeCapteurs2 = {"Camera"};
    vector<string> listeJambes = {"Hanche", "Jambe gauche", "Jambe droite"};
    Humanoide h = Humanoide("Optimus", listeCapteurs2, listeJambes);
    h.info();
    h.move("avant");
    h.move("gauche");

}