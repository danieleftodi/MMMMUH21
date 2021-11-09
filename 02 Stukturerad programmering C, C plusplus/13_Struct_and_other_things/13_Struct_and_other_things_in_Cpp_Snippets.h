//
//  05_Functions_part_one_in_Cpp_Snippets.h
//  05_Functions_part_one_in_Cpp
//
//  Created by DEft on 2021-09-28.
//

#ifndef Functions_part_one_in_Cpp_Snippets_h
#define Functions_part_one_in_Cpp_Snippets_h

//        sf_argv = f_argv[i];

/*
        if ( strcmp(sf_argv.substr(0,1).c_str(), "-") ) {
            printf("First char in varibale is: %s", sf_argv.substr(0,1).c_str() );
//            for (int u = 1; u < sf_argv.length(); u++) {
//                printf("char in f_argv: %s and lenght is: %lu\n", sf_argv.substr(0,1).c_str(), sf_argv.length());
//
//            }
            std::cout << "\n";
        }
*/
        
//        cf_argv = sf_argv.substr(0,1);
//
//        switch ( sf_argv.substr(0,1) ) {
//            case '-':
//                printf("sf_argv: %s\n", sf_argv.substr(0,1).c_str());
//                break;
//
//            default:
//                break;
//        }


printf("Make an input: ");

char strvar[100];
fgets (strvar, 100, stdin);

printf("Input was: %c\n\n", strvar[99]);


printf("Make an input: ");
int i, n; float x; char name[50];
n = scanf("%d%f%s", &i, &x, name);

printf("Input was: %s\n", name);

char buffer[256] = "";
printf ("Insert your full address: \n");
if (fgets(buffer, 256, stdin) != NULL) {
    printf ("Your address is: %s\n", buffer);
}
else {
    printf ("Error reading from stdin!\n");
}

#endif /* Functions_part_one_in_Cpp_Snippets_h */
