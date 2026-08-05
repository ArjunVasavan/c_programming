#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    // For sleep() function
#include <string.h>    // For string functions

/*
 * sprintf() and sscanf() - String Formatting and Parsing
 * =======================================================
 * 
 * What is sprintf()?
 * ------------------
 * sprintf() = "String Print Formatted" "So thats why printf is used inspute of print"
 * Writes formatted output to a STRING (not to screen/stdout)
 * Similar to printf(), but output goes to a character array
 * 
 * Syntax:
 * -------
 * int sprintf(char *str, const char *format, ...);
 * 
 * Parameters:
 * - str: destination string buffer
 * - format: format string (same as printf)
 * - ...: variable arguments to format
 * 
 * Returns: Number of characters written (excluding null terminator)
 * 
 * What is sscanf()?
 * -----------------
 * sscanf() = "String Scan Formatted"
 * Reads formatted input FROM a STRING (not from keyboard/stdin)
 * Similar to scanf(), but input comes from a character array
 * 
 * Syntax:
 * -------
 * int sscanf(const char *str, const char *format, ...);
 * 
 * Parameters:
 * - str: source string to parse
 * - format: format string (same as scanf)
 * - ...: pointers to variables to store parsed values
 * 
 * Returns: Number of successfully parsed items
 * 
 * Key Differences:
 * ----------------
 * printf()  → Writes to stdout (screen)
 * sprintf() → Writes to string buffer
 * 
 * scanf()   → Reads from stdin (keyboard)
 * sscanf()  → Reads from string buffer
 * 
 * Common Use Cases for sprintf():
 * -------------------------------
 * 1. Build formatted strings for later use
 * 2. Create file names dynamically
 * 3. Format data before writing to file
 * 4. Build SQL queries or commands
 * 5. Create log messages
 * 6. Concatenate numbers and text
 * 7. Convert numbers to strings
 * 
 * Common Use Cases for sscanf():
 * -------------------------------
 * 1. Parse formatted text data
 * 2. Extract numbers from strings
 * 3. Read configuration files
 * 4. Parse CSV data
 * 5. Extract date/time components
 * 6. Tokenize strings with specific format
 * 7. Convert strings to numbers with validation
 * 
 * Safety Notes:
 * -------------
 * sprintf() - UNSAFE! No buffer overflow protection
 *   → Use snprintf() instead (safer alternative)
 * 
 * sscanf() - Generally safe for parsing
 *   → But validate return value to ensure parsing success
 * 
 * Format Specifiers (same as printf/scanf):
 * -----------------------------------------
 * %d or %i  → Integer
 * %u        → Unsigned integer
 * %f        → Float
 * %lf       → Double
 * %c        → Character
 * %s        → String
 * %x        → Hexadecimal
 * %o        → Octal
 * %p        → Pointer
 * %%        → Literal % character
 */

int main() {
    printf("=== sprintf() and sscanf() - String Formatting Demo ===\n\n");
    sleep(1);
    
    // =================================================================
    // SPRINTF EXAMPLES
    // =================================================================
    printf("PART 1: sprintf() - Writing to Strings\n");
    printf("========================================\n\n");
    sleep(1);
    
    // Example 1: Basic sprintf usage
    printf("1. BASIC sprintf() USAGE:\n");
    char buffer1[100];
    int age = 25;
    sprintf(buffer1, "I am %d years old", age);
    printf("   Created string: \"%s\"\n", buffer1);
    printf("   Length: %ld characters\n\n", strlen(buffer1));
    sleep(1);
    
    // Example 2: Multiple variables
    printf("2. MULTIPLE VARIABLES:\n");
    char buffer2[100];
    char name[] = "Alice";
    int score = 95;
    float percentage = 95.5;
    sprintf(buffer2, "Student: %s, Score: %d, Percentage: %.2f%%", name, score, percentage);
    printf("   Created string: \"%s\"\n\n", buffer2);
    sleep(1);
    
    // Example 3: Building file names
    printf("3. BUILDING FILE NAMES:\n");
    char filename[50];
    int file_number = 42;
    sprintf(filename, "report_%03d.txt", file_number);
    printf("   Generated filename: \"%s\"\n", filename);
    
    sprintf(filename, "data_%d_%s.csv", 2024, "january");
    printf("   Generated filename: \"%s\"\n\n", filename);
    sleep(1);
    
    // Example 4: Formatting numbers
    printf("4. FORMATTING NUMBERS:\n");
    char num_str[50];
    int decimal = 255;
    sprintf(num_str, "Decimal: %d, Hex: 0x%X, Octal: 0%o", decimal, decimal, decimal);
    printf("   Formatted: \"%s\"\n\n", num_str);
    sleep(1);
    
    // Example 5: Building messages
    printf("5. BUILDING LOG MESSAGES:\n");
    char log_message[200];
    int error_code = 404;
    char error_type[] = "Not Found";
    sprintf(log_message, "[ERROR] Code: %d - %s - Please check the resource path", error_code, error_type);
    printf("   Log: \"%s\"\n\n", log_message);
    sleep(1);
    
    // Example 6: Return value of sprintf
    printf("6. RETURN VALUE OF sprintf():\n");
    char result[100];
    int chars_written = sprintf(result, "Testing sprintf return value");
    printf("   String: \"%s\"\n", result);
    printf("   Characters written: %d\n", chars_written);
    printf("   Actual length: %ld\n\n", strlen(result));
    sleep(1);
    
    // =================================================================
    // SSCANF EXAMPLES
    // =================================================================
    printf("\nPART 2: sscanf() - Reading from Strings\n");
    printf("=========================================\n\n");
    sleep(1);
    
    // Example 7: Basic sscanf usage
    printf("7. BASIC sscanf() USAGE:\n");
    char input1[] = "25";
    int parsed_age;
    int items_read = sscanf(input1, "%d", &parsed_age);
    printf("   Input string: \"%s\"\n", input1);
    printf("   Parsed integer: %d\n", parsed_age);
    printf("   Items successfully read: %d\n\n", items_read);
    sleep(1);
    
    // Example 8: Parsing multiple values
    printf("8. PARSING MULTIPLE VALUES:\n");
    char input2[] = "John 30 175.5";
    char parsed_name[50];
    int parsed_age2;
    float parsed_height;
    items_read = sscanf(input2, "%s %d %f", parsed_name, &parsed_age2, &parsed_height);
    printf("   Input string: \"%s\"\n", input2);
    printf("   Parsed name: %s\n", parsed_name);
    printf("   Parsed age: %d\n", parsed_age2);
    printf("   Parsed height: %.1f cm\n", parsed_height);
    printf("   Items successfully read: %d\n\n", items_read);
    sleep(1);
    
    // Example 9: Parsing CSV data
    printf("9. PARSING CSV DATA:\n");
    char csv_line[] = "Alice,25,95.5";
    char csv_name[50];
    int csv_age;
    float csv_score;
    items_read = sscanf(csv_line, "%[^,],%d,%f", csv_name, &csv_age, &csv_score);
    printf("   CSV input: \"%s\"\n", csv_line);
    printf("   Name: %s\n", csv_name);
    printf("   Age: %d\n", csv_age);
    printf("   Score: %.1f\n", csv_score);
    printf("   Items successfully read: %d\n\n", items_read);
    sleep(1);
    
    // Example 10: Parsing date format
    printf("10. PARSING DATE FORMAT:\n");
    char date_str[] = "2024-10-04";
    int year, month, day;
    items_read = sscanf(date_str, "%d-%d-%d", &year, &month, &day);
    printf("   Date string: \"%s\"\n", date_str);
    printf("   Year: %d\n", year);
    printf("   Month: %d\n", month);
    printf("   Day: %d\n", day);
    printf("   Items successfully read: %d\n\n", items_read);
    sleep(1);
    
    // Example 11: Parsing IP address
    printf("11. PARSING IP ADDRESS:\n");
    char ip_str[] = "192.168.1.100";
    int ip1, ip2, ip3, ip4;
    items_read = sscanf(ip_str, "%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4);
    printf("   IP string: \"%s\"\n", ip_str);
    printf("   Octets: %d.%d.%d.%d\n", ip1, ip2, ip3, ip4);
    printf("   Items successfully read: %d\n\n", items_read);
    sleep(1);
    
    // Example 12: Error handling with sscanf
    printf("12. ERROR HANDLING WITH sscanf():\n");
    char invalid_input[] = "Hello World";
    int invalid_number;
    items_read = sscanf(invalid_input, "%d", &invalid_number);
    printf("   Input string: \"%s\"\n", invalid_input);
    printf("   Items successfully read: %d\n", items_read);
    if (items_read == 0) {
        printf("   Result: Parsing FAILED - not a valid number!\n");
    }
    printf("\n");
    sleep(1);
    
    // =================================================================
    // COMBINED USAGE
    // =================================================================
    printf("\nPART 3: COMBINED sprintf() and sscanf()\n");
    printf("=========================================\n\n");
    sleep(1);
    
    // Example 13: Round-trip conversion
    printf("13. ROUND-TRIP CONVERSION:\n");
    
    // Original data
    int original_id = 12345;
    char original_name[] = "Bob";
    float original_salary = 75000.50;
    
    // Use sprintf to create formatted string
    char formatted[200];
    sprintf(formatted, "ID:%d|Name:%s|Salary:%.2f", original_id, original_name, original_salary);
    printf("   Created string: \"%s\"\n", formatted);
    
    // Use sscanf to parse it back
    int parsed_id;
    char parsed_name2[50];
    float parsed_salary;
    sscanf(formatted, "ID:%d|Name:%[^|]|Salary:%f", &parsed_id, parsed_name2, &parsed_salary);
    
    printf("   Parsed back:\n");
    printf("     ID: %d\n", parsed_id);
    printf("     Name: %s\n", parsed_name2);
    printf("     Salary: %.2f\n\n", parsed_salary);
    sleep(1);
    
    // =================================================================
    // SUMMARY
    // =================================================================
    printf("\nKey Takeaways:\n");
    printf("--------------\n");
    printf("sprintf():\n");
    printf("  ✓ Writes formatted output to a STRING\n");
    printf("  ✓ Like printf() but output goes to buffer\n");
    printf("  ✓ Returns number of characters written\n");
    printf("  ✓ Use for: building strings, file names, messages\n");
    printf("  ⚠ WARNING: No buffer overflow protection!\n");
    printf("  → Prefer snprintf() for safety\n\n");
    
    printf("sscanf():\n");
    printf("  ✓ Reads formatted input FROM a STRING\n");
    printf("  ✓ Like scanf() but input comes from buffer\n");
    printf("  ✓ Returns number of items successfully read\n");
    printf("  ✓ Use for: parsing text, extracting data, tokenizing\n");
    printf("  ✓ Always check return value for parsing success\n\n");
    
    printf("Together:\n");
    printf("  → Powerful string manipulation tools\n");
    printf("  → sprintf builds, sscanf parses\n");
    printf("  → Perfect for data serialization/deserialization\n");
    
    return 0;
}
