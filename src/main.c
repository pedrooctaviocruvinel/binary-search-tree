#include <stdio.h>

#include "binary_search_tree.h"
#include "product.h"

int main(void)
{
    BinarySearchTree product_tree;

    bst_init(&product_tree, sizeof(Product), compare_products);

    Product products[] = {
        {"CLO-TSH-001", "Classic Cotton T-Shirt"},
        {"CLO-JEA-002", "Slim Fit Jeans"},
        {"ACC-BEL-002", "Leather Belt"},
        {"ACC-WAT-001", "Digital Watch"},
        {"CLO-JAC-003", "Winter Jacket"},
        {"AUY-QJAC-003", "Yamete"},
        {"CLO-YUC-003", "Kudasai"},
        {"CLO-HOO-004", "Classic Pullover Hoodie"},
        {"CLO-SHO-005", "Casual Button-Down Shirt"},
        {"CLO-SWE-006", "Wool Sweater"},
        {"CLO-SOR-007", "Denim Shorts"},
        {"CLO-TRS-008", "Formal Trousers"},
        {"CLO-SKT-009", "Pleated Skirt"},
        {"CLO-DRS-010", "Summer Dress"},
        {"CLO-COA-011", "Long Wool Coat"},
        {"CLO-VES-012", "Puffer Vest"},
        {"CLO-CAP-013", "Baseball Cap"},
        {"CLO-SOC-014", "Cotton Ankle Socks"},
        {"CLO-GLO-015", "Winter Gloves"},
        {"CLO-SCA-016", "Wool Scarf"},
        {"ACC-BAG-017", "Leather Backpack"},
        {"ACC-WAL-018", "Classic Leather Wallet"},
        {"ACC-SUN-019", "Polarized Sunglasses"},
        {"ACC-RIN-020", "Silver Ring"},
        {"ACC-NEC-021", "Gold Necklace"},
        {"ACC-BRA-022", "Leather Bracelet"},
        {"ACC-EAR-023", "Silver Earrings"},
        {"ACC-HAT-024", "Wide Brim Hat"},
        {"ACC-BPK-025", "Travel Backpack"},
        {"ACC-KEY-026", "Metal Keychain"},
        {"SHO-SNE-027", "Running Sneakers"},
        {"SHO-BOO-028", "Leather Boots"},
        {"SHO-SAN-029", "Casual Sandals"},
        {"SHO-FOR-030", "Formal Oxford Shoes"},
        {"SHO-SLI-031", "Indoor Slippers"},
        {"ELE-PHO-032", "Smartphone"},
        {"ELE-HDP-033", "Wireless Headphones"},
        {"ELE-MOU-034", "Wireless Mouse"},
        {"ELE-KEY-035", "Mechanical Keyboard"},
        {"ELE-MON-036", "27-Inch Monitor"},
        {"ELE-TAB-037", "Android Tablet"},
        {"ELE-CHA-038", "Fast USB-C Charger"},
        {"ELE-SPK-039", "Bluetooth Speaker"},
        {"ELE-WEB-040", "HD Webcam"},
        {"HOM-MUG-041", "Ceramic Coffee Mug"},
        {"HOM-LMP-042", "Desk Lamp"},
        {"HOM-PIL-043", "Decorative Pillow"},
        {"HOM-BLA-044", "Cotton Blanket"},
        {"HOM-BOT-045", "Stainless Steel Water Bottle"},
        {"HOM-CLT-046", "Nonstick Cooking Pan"},
    };

    size_t product_count = sizeof(products) / sizeof(products[0]);

    for (size_t i = 0; i < product_count; i++)
    {
        bst_insert(&product_tree, &products[i]);
    }

    printf("\n--- products in order ---\n\n");
    bst_in_order(&product_tree, print_product);

    Product search_product = {.sku = "ELE-WEB-040"};

    const Product *product = bst_find(&product_tree, &search_product);

    printf("\n--- searching for product: %s ---\n", product->sku);
    printf("--- product found: %s ---\n", product->name);

    printf("\n--- removing product: %s ---\n", product->sku);

    int removed = bst_remove(&product_tree, product);

    if (removed == 1)
    {
        printf("--- product removed successfully ---\n");
    }
    else
    {
        printf("--- error on removing product ---\n");
    }

    printf("\n--- tree analysis ---\n");

    printf("\n--- tree nodes: %zu ---\n", bst_count(&product_tree));
    printf("--- tree height: %d ---\n", bst_height(&product_tree));
    printf("--- tree memory usage: %zu bytes ---\n", bst_memory_usage(&product_tree));
    printf("--- size of BinarySearchTree: %zu bytes ---\n", sizeof(BinarySearchTree));
    printf("--- size of TreeNode: %zu bytes ---\n", sizeof(TreeNode));
    printf("--- size of Product: %zu bytes ---\n", sizeof(Product));

    bst_destroy(&product_tree);

    if (product_tree.root == NULL)
        printf("\n--- product tree was destroyed ---\n");

    return 0;
}
