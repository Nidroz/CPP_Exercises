# Réponses - TP3 - C++ - Nadir SIDHOUM

## EXERCICE 1
### CAS A
#### Question 1
Pourquoi n'y a-t-il pas de relation entre last_wheel et wheels[3] contrairement à first_wheel et wheels[0] ?

> Il n'y a pas de relation entre last_wheel et wheels[3]last_wheel et wheels[3],
contrairement à first_wheel et wheels[0], car last_wheel n'est pas un référence.
last_wheel copie uniquement car.wheels.back(); (wheels[3]).
Ce n'est last_wheel qui instancie wheels[3] (ou wheeles tout court).


### CAS B
#### Question 1
Dans le graphe d'ownership, on distingue un pointeur d'une référence, via une référence (pointeur: flèche en pointillée qui part d'un bloc de donnée).
(référence: flèche en pointillée qui part d'un bloc de référence (bloc en pointillé))

#### Question 2
Un pointeur nul (`nullptr`) est représenté par une référence à un cercle vide avec une croix à l'intérieur.

#### Question 3
En termes de code, les deux différences principales entre un pointeur-observant et une référence sont:
- On peut créer un pointeur vide (= à `nullptr`), mais pas une référence vide (référence vers toujours référence à une zone de donnée).
 
- Les pointeurs-obersants sont mutables dans les données qu'ils observent, de plus ils sont réassignables.
Alors que les références feront toujours référence au même bloc de données.


### CAS C
(Voir de notes, et fichier `CasC.cpp`)
```cpp
#include <memory>
#include <vector>

struct Product
{};

struct Client
{
    public:
        ~Client() {
            for (auto* product : products) {
                delete product;
            } 
        }

    std::vector<Product*> products;
};

int main()
{
    auto client = Client {};

    client.products.push_back(new Product{});
    client.products.push_back(new Product{});

    auto* first_product = client.products.front();
                                                    // <-- on est ici
    client.products.push_back(new Product{});
    return 0;
}
```



## EXERCICE 2
### Question 1
(voir fichier `exo2.cpp`)
```cpp
#include <iostream>

int add(int a, int b)
{
    return a + b;
}

void add_to(int& a, int b)
{
    a += b;
}

int main()
{
    int x = 10;
    int y = add(x, x);
    add_to(y, 22);
    std::cout << x << " " << y << std::endl;
    return 0;
}
```

### Question 2

