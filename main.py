class Product:
    def __init__(self, product_id, name, price, stock):
        self.product_id = product_id
        self.name = name
        self.price = price
        self.stock = stock

    def update_stock(self, quantity):
        if quantity <= self.stock:
            self.stock -= quantity
            return True
        return False

class ShoppingCart:
    def __init__(self):
        self.cart = {}

    def add_to_cart(self, product, quantity):
        if product.update_stock(quantity):
            if product.product_id in self.cart:
                self.cart[product.product_id]["quantity"] += quantity
            else:
                self.cart[product.product_id] = {"product": product, "quantity": quantity}
            print(f"Added {quantity} of {product.name} to cart.")
        else:
            print("Not enough stock available!")

    def view_cart(self):
        print("\nShopping Cart:")
        for item in self.cart.values():
            product = item["product"]
            print(f"{product.name} - ${product.price} x {item['quantity']} = ${product.price * item['quantity']}")

    def checkout(self):
        total = sum(item['product'].price * item['quantity'] for item in self.cart.values())
        print(f"\nTotal Amount: ${total}")
        print("Checkout successful!")
        self.cart.clear()

class ECommerceSystem:
    def __init__(self):
        self.products = [
            Product(1, "Laptop", 800, 5),
            Product(2, "Smartphone", 500, 10),
            Product(3, "Headphones", 100, 15)
        ]
        self.cart = ShoppingCart()

    def display_products(self):
        print("\nAvailable Products:")
        for product in self.products:
            print(f"{product.product_id}. {product.name} - ${product.price} (Stock: {product.stock})")

    def run(self):
        while True:
            print("\n1. View Products\n2. Add to Cart\n3. View Cart\n4. Checkout\n5. Exit")
            choice = input("Enter choice: ")
            
            if choice == "1":
                self.display_products()
            elif choice == "2":
                product_id = int(input("Enter product ID: "))
                quantity = int(input("Enter quantity: "))
                product = next((p for p in self.products if p.product_id == product_id), None)
                if product:
                    self.cart.add_to_cart(product, quantity)
                else:
                    print("Product not found!")
            elif choice == "3":
                self.cart.view_cart()
            elif choice == "4":
                self.cart.checkout()
            elif choice == "5":
                print("Exiting system.")
                break
            else:
                print("Invalid choice! Try again.")

if __name__ == "__main__":
    system = ECommerceSystem()
    system.run()
