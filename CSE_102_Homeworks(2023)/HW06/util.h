#include <stdio.h>
#ifndef UTIL_H
#define UTIL_H

/*_____PART_1_MENU_____*/

int menu();

int get_pID();

int count_line(const char *filename);

void locate_f_stream(FILE *fp, int desired_line);

int is_equal(const char *s1, const char *s2);

/*_____PART_2_FILE_OPERATIONS_____*/

int display_file_operations_menu();

int add_new_product();

void delete_line(char *filename, int desired_line);

void print_str_to_file(char *str, FILE *fp);


/*_____PART_3_SEARCH_PRODUCT_____*/

int display_stock_status_menu();

int display_products();

//void filter_products();

/*_____PART_4_CHECK_STOCK_STATUS_____*/

int display_query_menu();

void query_stock();

void list_stock();

void list_out_of_stock();

void print_product_by_pID(int pID);

/*_____PART_5_BRAND_STOCK_CONTROL_____*/

void brand_stock_control();

double find_product_price(int pID);

/*_____PART_6_STOCK_REPORT_____*/

//void export_report();

#endif