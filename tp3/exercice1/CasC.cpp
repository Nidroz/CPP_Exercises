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