#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // Include the header for toupper function

#include "costumer.h"

int main() {
    struct Customer customer = getCustomerInfo();

    printf("\nYou entered:\n%s %s\n%s,\n%s, %s,\n%s\n",
           customer.firstName, customer.lastName,
           customer.streetAddress,
           customer.city, customer.province,
           customer.postalCode);

    return 0;
}
int isValidPostalCode(const char *code) {
    if (strlen(code) != 6) {
        return 0; 
    }

    return 1;
}

struct Customer getCustomerInfo() {
    struct Customer customer;

    do {
        printf("Enter your first name: ");
        fgets(customer.firstName, sizeof(customer.firstName), stdin);
        customer.firstName[strcspn(customer.firstName, "\n")] = '\0';
    } while (customer.firstName[0] == '\0');

    // Prompt for last name
    do {
        printf("Enter your last name: ");
        fgets(customer.lastName, sizeof(customer.lastName), stdin);
        customer.lastName[strcspn(customer.lastName, "\n")] = '\0';
    } while (customer.lastName[0] == '\0');

    // Prompt for street address
    printf("Enter your street address: ");
    fgets(customer.streetAddress, sizeof(customer.streetAddress), stdin);
    customer.streetAddress[strcspn(customer.streetAddress, "\n")] = '\0';

    // Prompt for city
    printf("Enter your city: ");
    fgets(customer.city, sizeof(customer.city), stdin);
    customer.city[strcspn(customer.city, "\n")] = '\0';

    // Prompt for province
    printf("Enter your province: ");
    fgets(customer.province, sizeof(customer.province), stdin);
    customer.province[strcspn(customer.province, "\n")] = '\0';

    // Prompt for postal code
    do {
        printf("Enter your postal code: ");
        fgets(customer.postalCode, sizeof(customer.postalCode), stdin);
        customer.postalCode[strcspn(customer.postalCode, "\n")] = '\0';

        // Convert to uppercase
        for (int i = 0; i < 6; i++) {
            customer.postalCode[i] = toupper(customer.postalCode[i]);
        }

    } while (!isValidPostalCode(customer.postalCode));

    return customer;
}
