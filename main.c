#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 5
#define MAX_CART 10

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

typedef struct {
    Product product;
    int quantity;
} CartItem;

Product products[MAX_PRODUCTS] = {
    {1, "Laptop", 750.00},
    {2, "Smartphone", 500.00},
    {3, "Headphones", 100.00},
    {4, "Keyboard", 50.00},
    {5, "Mouse", 25.00}
};

CartItem cart[MAX_CART];
int cartSize = 0;

void displayProducts() {
    printf("\nAvailable Products:\n");
    printf("ID\tName\t\tPrice\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%d\t%s\t$%.2f\n", products[i].id, products[i].name, products[i].price);
    }
}

void addToCart() {
    int productId, quantity;
    printf("Enter Product ID to add to cart: ");
    scanf("%d", &productId);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    if (productId < 1 || productId > MAX_PRODUCTS || quantity <= 0) {
        printf("Invalid product selection!\n");
        return;
    }

    if (cartSize >= MAX_CART) {
        printf("Cart is full!\n");
        return;
    }

    cart[cartSize].product = products[productId - 1];
    cart[cartSize].quantity = quantity;
    cartSize++;
    printf("Product added to cart successfully!\n");
}

void viewCart() {
    if (cartSize == 0) {
        printf("Cart is empty!\n");
        return;
    }
    
    printf("\nShopping Cart:\n");
    printf("ID\tName\t\tPrice\tQuantity\tTotal\n");
    float totalAmount = 0;
    for (int i = 0; i < cartSize; i++) {
        float total = cart[i].product.price * cart[i].quantity;
        printf("%d\t%s\t$%.2f\t%d\t\t$%.2f\n", cart[i].product.id, cart[i].product.name, cart[i].product.price, cart[i].quantity, total);
        totalAmount += total;
    }
    printf("Total Amount: $%.2f\n", totalAmount);
}

void checkout() {
    if (cartSize == 0) {
        printf("Cart is empty! Nothing to checkout.\n");
        return;
    }
    
    viewCart();
    printf("\nProceeding to checkout... Payment Successful!\n");
    cartSize = 0;
}

void mainMenu() {
    int choice;
    while (1) {
        printf("\nE-Commerce Shopping System\n");
        printf("1. View Products\n");
        printf("2. Add to Cart\n");
        printf("3. View Cart\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayProducts();
                break;
            case 2:
                addToCart();
                break;
            case 3:
                viewCart();
                break;
            case 4:
                checkout();
                break;
            case 5:
                printf("Exiting system. Thank you for shopping!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

int main() {
    mainMenu();
    return 0;
}
