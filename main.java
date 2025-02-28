import java.util.*;

class Product {
    int id;
    String name;
    double price;

    Product(int id, String name, double price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }
}

class ShoppingCart {
    private List<Product> cart = new ArrayList<>();

    void addProduct(Product product) {
        cart.add(product);
        System.out.println(product.name + " added to cart.");
    }

    void viewCart() {
        if (cart.isEmpty()) {
            System.out.println("Cart is empty!");
            return;
        }
        System.out.println("Your Shopping Cart:");
        for (Product p : cart) {
            System.out.println(p.id + " - " + p.name + " - $" + p.price);
        }
    }

    double checkout() {
        double total = 0;
        for (Product p : cart) {
            total += p.price;
        }
        cart.clear();
        return total;
    }
}

public class ECommerceSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Product> products = Arrays.asList(
            new Product(1, "Laptop", 800.00),
            new Product(2, "Smartphone", 500.00),
            new Product(3, "Headphones", 100.00)
        );
        ShoppingCart cart = new ShoppingCart();

        while (true) {
            System.out.println("\nE-Commerce Shopping System");
            System.out.println("1. View Products");
            System.out.println("2. Add Product to Cart");
            System.out.println("3. View Cart");
            System.out.println("4. Checkout");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("\nAvailable Products:");
                    for (Product p : products) {
                        System.out.println(p.id + " - " + p.name + " - $" + p.price);
                    }
                    break;
                case 2:
                    System.out.print("Enter product ID to add to cart: ");
                    int productId = scanner.nextInt();
                    products.stream().filter(p -> p.id == productId).findFirst().ifPresent(cart::addProduct);
                    break;
                case 3:
                    cart.viewCart();
                    break;
                case 4:
                    System.out.println("Total amount: $" + cart.checkout());
                    break;
                case 5:
                    System.out.println("Thank you for shopping with us!");
                    return;
                default:
                    System.out.println("Invalid choice! Try again.");
            }
        }
    }
}
