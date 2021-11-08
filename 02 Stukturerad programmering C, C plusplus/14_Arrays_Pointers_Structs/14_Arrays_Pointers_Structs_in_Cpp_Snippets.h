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


#endif /* Functions_part_one_in_Cpp_Snippets_h */

int A[10] = {6, 8, 13, 17, 20, 22, 25, 28, 30, 35};
    int l = 0, h = 9, key, mid;
    //cout << "Enter Key";
    //cin >> key;

    while (l <= h)
    {
        mid = (l+h)/2;
        if(key == A[mid])
        {
            cout << "Found at " << mid << endl;
            return 0;
        }
        else if (key < A[mid])
        {
            h = mid - l;
        }
        else
        {
            l = mid + l;
        }
    }
    return 0;
