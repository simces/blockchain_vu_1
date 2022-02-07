#include "functions.hpp"
#include <string>

using namespace std;
using namespace std::chrono;


string hashing(string hashInput){

    if(hashInput == " ") return "961b6dd3ede3cb8ecbaacbd68de040cd78eb2ed5889130cceb4c49268ea4d506";

    const int initial_hash_seed = 9464;                 // initial seed
    unsigned int initial_hash = initial_hash_seed;

    for(int i = 0; i <= hashInput.length(); i++){       // random h
        initial_hash = (initial_hash * 47) + int(hashInput[i]) + hashInput.length() * 27;
    }


    string initial_hash_str = to_string(initial_hash);      // 4 choosing char
    int initial_hash_str_size = initial_hash_str.size();
    
    const string hex = "0123456789abcdef";          // hex str
    string hashOutput;

    unsigned int random_var = initial_hash * initial_hash_seed;     // random variable
    int random_num = 17;

    for(int i = 0; i < 64; i++){        // for 64c // randomizing var // creating hashout
        random_var += initial_hash_str[i * random_num % initial_hash_str_size] + initial_hash_seed * i * 3;
        hashOutput += hex[random_var % 16];
        random_num = random_num * 3 - 11;
    }

    return hashOutput;
}

void readFile(string file){

    string input, output;
    ifstream in("fileInput/" + file + ".txt");
    ofstream out("fileOutput/" + file + "_hash.txt");

    if(!in.is_open()){
        cout << "Failed opening " << file << endl;
        return;}

    if (file == "empty"){           // if file is empty
        out << "961b6dd3ede3cb8ecbaacbd68de040cd78eb2ed5889130cceb4c49268ea4d506";
    }
    
    string line;

    // high_resolution_clock::time_point t1 = high_resolution_clock::now();    // konstitucijai

    while(getline(in, line)){
        out << hashing(line) << endl;
    }

    // cout << "failo 'konstitucija.txt' hash'avimo laikas: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;

    in.close();
    out.close();

}

void consoleInput(){
    string input;
    cout << "Your input: ";
    cin >> input;

    cout << hashing(input);

}

void gen_random_file(int length, string file){

    ofstream out;
    out.open("fileInput/" + file + ".txt");


    string random_str;
    static const char alphanum[] = 
        "0123456789"
        "ABCDEFGHIJKLMNOPRSTUVWXYZ"
        "abcdefghijklmnoprstuvwxyz";

    for(int i = 0; i < length; ++i){
        random_str += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    cout << random_str << "  " << endl;     // ...
    
    out << random_str;
    out.close();
};

string gen_random_str(int length){
    string random_str;
    static const char alphanum[] = 
        "0123456789"
        "ABCDEFGHIJKLMNOPRSTUVWXYZ"
        "abcdefghijklmnoprstuvwxyz";

    for(int i = 0; i < length; ++i){
        random_str += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    // cout << random_str << "  " << endl;     // ...
    return random_str;
};

void fileInput(){
    int choice;
    char temp;

    cout << "Select file: " << endl
    << "---------------" << endl
    << "1. a.txt" << endl
    << "2. b.txt" << endl
    << "3. randomText1.txt" << endl
    << "4. randomText2.txt" << endl
    << "5. 1500symbols_1.txt" << endl
    << "6. 1500symbols_2.txt" << endl
    << "7. empty.txt" << endl
    << "8. konstitucija.txt" << endl
    << "9. all files" << endl
    << "----------------" << endl;

    choiceCheck(choice, 9);

    if(choice == 5 || choice == 6){
        cout << "Do you want to generate new file? (Y/N)" << endl;
        cin >> temp;

        if(temp == 'Y' || temp == 'y'){
            if(choice == 5){
                gen_random_file(1500, "1500symbols_1");
            }
            else gen_random_file(1500, "1500symbols_2");
        }

    }

    if(choice == 1) readFile("a");
    else if(choice == 2) readFile("b");
    else if(choice == 3) readFile("randomText1");
    else if(choice == 4) readFile("randomText2");
    else if(choice == 5) readFile("1500symbols_1");
    else if(choice == 6) readFile("1500symbols_2");
    else if(choice == 7) readFile("empty");
    else if(choice == 8) readFile("konstitucija");
    else if(choice == 9) {
        readFile("a");
        readFile("b");
        readFile("randomText1");
        readFile("randomText2");
        readFile("1500symbols_1");
        readFile("1500symbols_2");
        readFile("empty");
        readFile("konstitucija");
    }

}

void comparison(){          // comparing custom_hash to md5, sha1, sha256

    // MD5 md5;
    // SHA1 sha1;
    // SHA256 sha256;

    // reading file / using konstitucija.txt

    ifstream in("fileInput/konstitucija.txt");
    if(!in.is_open()){
        cout << "Failed opening 'konstitucija.txt'.";
        exit(0);
    }

    in.close();

    cout << endl <<  "Comparing different hashing algorithm times:" << endl
    << "----------------------------------------------" << endl;

    string line;

    double custom_hash_time = 0;
    double md5_hash_time = 0;
    double sha1_hash_time = 0;
    double sha256_hash_time = 0;

    high_resolution_clock::time_point t1; // high_resolution_clock::now();        // CUSTOM HASH

    for(int i = 0; i < 2000; i++){

        in.open("fileInput/konstitucija.txt");

        while(getline(in, line)){

            t1 = high_resolution_clock::now();
            hashing(line);
            custom_hash_time += chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count();
        
            t1 = high_resolution_clock::now();
            md5(line);
            md5_hash_time += chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count();

            t1 = high_resolution_clock::now();
            sha1(line);
            sha1_hash_time += chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count();

            t1 = high_resolution_clock::now();
            sha256(line);
            sha256_hash_time += chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count();
        }
        in.close();
    }

    cout << "Custom hash time: " << custom_hash_time / 1000. << "s." << endl
    << "Md5 hash time: " << md5_hash_time / 1000. << "s." << endl
    << "Sha1 hash time: " << sha1_hash_time / 1000. << "s." << endl
    << "Sha256 hash time: " << sha256_hash_time / 1000. << "s." << endl
    << "----------------------------------------------" << endl << endl;

    // in.close();

    // t1 = high_resolution_clock::now();        // MD5
    // while(getline(in, line)){
    //     md5(line);
    // }
    // cout << "Custom hash time: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;

    // t1 = high_resolution_clock::now();        // SHA1
    // while(getline(in, line)){
    //     sha1(line);
    // }
    // cout << "Custom hash time: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;

    // t1 = high_resolution_clock::now();        // SHA256
    // while(getline(in, line)){
    //     sha256(line);
    // }
    // cout << "Custom hash time: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;

}


void collisions(){

    int fileSizes[4] = {10, 100, 500, 1000};
    int collisions = 0;

    cout << "Starting collision test:" << endl
         << "------------------------" << endl;
    cout << "Collisions: ";

    string a1, b2;

    for(int x = 0; x < 4; x++){
        for(int i = 0; i < 25000; i++){
            a1 = gen_random_str(fileSizes[x]);
            b2 = gen_random_str(fileSizes[x]);

            if(hashing(a1) == hashing(b2)) collisions++;
        }
    }

    if(collisions > 0) cout << collisions << " out of 100'000 tests";
    else cout << "0 out of 100'000. None detected.";

    // cout << a1 << endl << b2 << endl << "-----------------" << endl;
}

// !

string transform(char temp){

    while(temp){
        if(temp == '0') return "0000";
        else if(temp == '1') return "0001";
        else if(temp == '2') return "0010";
        else if(temp == '3') return "0011";
        else if(temp == '4') return "0100";
        else if(temp == '5') return "0101";
        else if(temp == '6') return "0110";
        else if(temp == '7') return "0111";
        else if(temp == '8') return "1000";
        else if(temp == '9') return "1001";
        else if(temp == 'A' || temp == 'a') return "1010";
        else if(temp == 'B' || temp == 'b') return "1011";
        else if(temp == 'C' || temp == 'c') return "1100";
        else if(temp == 'D' || temp == 'd') return "1101";
        else if(temp == 'E' || temp == 'e') return "1110";
        else if(temp == 'F' || temp == 'f') return "1111";
    }
    
    return 0;
}


void difference(){

    double bits_min = 256, bits_max = 0, bits_avg = 0;
    double hex_min = 64, hex_max = 0, hex_avg = 0;

    string temp_str, a1, b2;

    int fileSizes[4] = {10, 100, 500, 1000};

    cout << endl
         << "Starting difference test" << endl
         << "------------------------" << endl;

    for(int x = 0; x < 4; x++){
        for(int i = 0; i < 25000; i++){
            temp_str = gen_random_str(fileSizes[x]);
            a1 = hashing("w" + temp_str);
            b2 = hashing("l" + temp_str);

            double diff_hex = 0;
            double diff_bit = 0;

            for(int str_i = 0; str_i < a1.length(); str_i ++){
                // hex

                if(a1[str_i] != b2[str_i]) diff_hex++;

                //bitu lygmenyje
                string bit_1 = transform(a1[str_i]);
                string bit_2 = transform(b2[str_i]);

                for(int j = 0; j < bit_1.size(); j++){
                    if(bit_1[j] != bit_2[j]) diff_bit++;
                }
            }
            
            if(diff_hex < hex_min) hex_min = diff_hex;
            if(diff_hex > hex_max) hex_max = diff_hex;
            hex_avg += diff_hex;

            if(diff_bit < bits_min) bits_min = diff_bit;
            if(diff_bit > bits_max) bits_max = diff_bit;
            bits_avg += diff_bit;
        }
    }

    hex_avg = hex_avg / 64 / 100000 * 100;
    bits_avg = bits_avg / 256 / 100000 * 100;
    
    cout << "                               hex     bits" << endl;
    cout << "Minimum difference in pairs:   " << hex_min << "      " << bits_min << endl;
    cout << "Maximum difference in pairs:   " << hex_max << "      " << bits_max << endl;
    cout << "Average difference in pairs:   " << setprecision(3) << hex_avg << "%   " << setprecision(3) << bits_avg << "%" << endl;

}


int choiceCheck(int &rt, int count){				// choice checkup
	while(true){
        int t = 0;
		cin >> rt;
		
        for(int i = count; i > 0; i--){
            if(i == rt) t++;
        }

        if(t == 1) return rt;
        else cout << "Wrong input. Try again. " << endl;

	}
};