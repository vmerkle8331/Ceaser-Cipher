#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encrypt(string plaintext, string key) {
    string ciphertext = "";
    for (char letter : plaintext) {
        if (isalpha(letter)) {
            int ASCII_value = (int)tolower(letter) - 'a';
            int shifted_value = (ASCII_value + key[0] - 'a' + 26) % 26;
            char new_letter = 'a' + shifted_value;
            ciphertext += new_letter;
        }
        else {
            ciphertext += letter;
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    string plaintext = "";
    for (char letter : ciphertext) {
        if (isalpha(letter)) {
            int ASCII_value = (int)tolower(letter) - 'a';
            int shifted_value = (ASCII_value - key[0] + 'a' + 26) % 26;
            char new_letter = 'a' + shifted_value;
            plaintext += new_letter;
        }
        else {
            plaintext += letter;
        }
    }
    return plaintext;
}

int main() {
    string plaintext, key;
    ifstream input_file;
    ofstream output_file;

    // Encrypt the text in the class-common input file
    input_file.open("class_input_c.txt");
    if (input_file.is_open()) {
        getline(input_file, plaintext);
        getline(input_file, key);
        string encrypted_text = encrypt(plaintext, key);
        output_file.open("Doe_output_5c.txt");
        output_file << encrypted_text;
        output_file.close();
    }
    else {
        cout << "Unable to open file";
    }
    input_file.close();

    // Decrypt the ciphertext in the class-common output file
    plaintext = "";
    key = "";
    input_file.open("Doe_output_5c.txt");
    if (input_file.is_open()) {
        getline(input_file, plaintext);
        getline(input_file, key);
        string decrypted_text = decrypt(plaintext, key);
        output_file.open("Doe_output_5d.txt");
        output_file << decrypted_text;
        output_file.close();
    }
    else {
        cout << "Unable to open file";
    }
    input_file.close();

    // Encrypt the text in the own-common input file
    input_file.open("own_input_e.txt");
    if (input_file.is_open()) {
        getline(input_file, plaintext);
        getline(input_file, key);
        string encrypted_text = encrypt(plaintext, key);
        output_file.open("Doe_output_5e.txt");
        output_file << encrypted_text;
        output_file.close();
    }
    else {
        cout << "Unable to open file";
    }
    input_file.close();

    // Decrypt the ciphertext in the own-common output file
    plaintext = "";
    key = "";
    input_file.open("Doe_output_5e.txt");
    if (input_file.is_open()) {
        getline(input_file, plaintext);
        getline(input_file, key);
        string decrypted_text = decrypt(plaintext, key);
        output_file.open("own_output_5e.txt");
        output_file << decrypted_text;
        output_file.close();
    }
    else {
        cout << "Unable to open file";
    }
    input_file.close();
}