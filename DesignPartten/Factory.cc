#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;


class Product
{
public:
    virtual void show() = 0;
    virtual ~Product() {}
};

class ProductA
: public Product
{
public:
    ProductA() { cout << "ProductA()" << endl; }
    void show() override { cout << "void ProductA::show()" << endl; }
    ~ProductA() { cout << "~ProductA()" << endl; }
};


class ProductB
: public Product
{
public:
    ProductB() { cout << "ProductB()" << endl; }
    void show() override { cout << "void ProductB::show()" << endl; }
    ~ProductB() { cout << "~ProductB()" << endl; }
};

class Factory
{
public:
    virtual Product *createProduct() = 0;
    virtual ~Factory() {}
};


class FactoryA
: public Factory
{
public:
    FactoryA() { cout << "FactoryA()" << endl; }
    Product *createProduct() override { return new ProductA(); }
    ~FactoryA() { cout << "~FactoryA()" << endl; }
};


class FactoryB
: public Factory
{
public:
    FactoryB() { cout << "FactoryB()" << endl; }
    Product *createProduct() override { return new ProductB(); }
    ~FactoryB() { cout << "~FactoryB()" << endl; }
};

int main (int argc, char *argv[])
{
    unique_ptr<Factory> factoryA(new FactoryA());
    unique_ptr<Product> productA(factoryA->createProduct());
    productA->show();
    cout << endl;

    unique_ptr<Factory> factoryB(new FactoryB());
    unique_ptr<Product> productB(factoryB->createProduct());
    productB->show();

    return 0;
}










