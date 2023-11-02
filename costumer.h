#ifndef CUSTOMER_INFO_H
#define CUSTOMER_INFO_H

struct Customer {
    char firstName[50];
    char lastName[50];
    char streetAddress[100];
    char city[50];
    char province[3];
    char postalCode[7];
};

int isValidPostalCode(const char *code);
struct Customer getCustomerInfo();

#endif