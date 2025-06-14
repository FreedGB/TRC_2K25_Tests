## Un robot, c'est quoi?
D'après [Wikipédia](https://fr.wikipedia.org/wiki/Robot):

> Un **robot** est un dispositif mécatronique (alliant mécanique, électronique et informatique) conçu pour accomplir automatiquement des tâches imitant ou reproduisant, dans un domaine précis, des actions humaines.

Ainsi, à la manière d'un être humain, un robot peut être capable de 3 choses fondamentales:
- **percevoir**, c'est-à-dire recueillir des informations de son environnement. Cela se fait grâce à ce qu'on appelle des **capteurs**;
- **déciser**, c'est-à-dire analyser les informations reçues et déciser de la conduite à tenir. C'est ce que représente le **programme** du robot, qui lui dit quoi faire;
- **agir** sur son environnement en conséquence grâce à ce qu'on appelle des **effecteurs** (ce qui *effectue* une action). Un effecteur peut être un bras, une aile, une hélice, etc.

> [!NOTE]  
> Il est assez tentant de remplacer **effecteur** par **moteur**, mais il pourrait y avoir un amalgame avec les moteurs mécaniques.


Si nous focalisons uniquement sur ces trois fonctions, une machine n'a pas forcément besoin de ressembler à Terminator ou R2D2 pour être appelé de robot.



## Définition de la classe Robot
En nous référant à la définition énoncée précédemment, un robot est donc un objet possédant des capteurs et des effecteurs...

Nous utiliserons donc cette définition d'un robot afin de modéliser la classe `Robot` dans notre programme.

```c++
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
};
```

Voilà! Pas très complexe, mais c'est l'essentiel.



## Création de deux sous-classes
Nous allons créer deux types de robots: une voiture et un robot humanoïde. Ces deux robots doivent hériter de la classe `Robot`.

```c++
class Voiture : public Robot
{
    public:
        Voiture(string nom, vector<string> capteurs, vector<string> roues)
        {
            this->setNom(nom);
            this->setCapteurs(capteurs);
            this->setEffecteurs(roues);
        }
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
};
```


## Implémentation de la méthode `move()`
Il est temps de faire bouger les choses.

Nos robots doivent êtres capables de se déplacer dans leur environnement. Cependant, une voiture ne se déplace pas de la même manière qu'un humanoïde. Donc, la classe mère `Robot` ne devra définir qu'une méthode abstraite `move()`, et les classes filles les implémenterons.

```c++
// Methode virtuelle dans la classe Robot
virtual void move(string direction) = 0;
```

```c++
// Implementation dans la classe Voiture
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
}
```

```c++
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
```


## Test final
Bon, testons désormais l'ensemble du programme dans la fonction `main`

```c++
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
```