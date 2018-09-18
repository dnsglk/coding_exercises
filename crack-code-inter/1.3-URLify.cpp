#include "common.h"

using namespace std;

void URLify(string& url) {
    
    uint32_t origSize = url.size();
    uint32_t spacesLeft = 0;    

    // Collect idx at which spaces reside
    for (uint32_t i = 0 ; i < origSize; ++i) {
        if (url.at(i) == ' ') {
            ++spacesLeft;
        }
    }

    // Not a part of an algo
    url += string(spacesLeft * 3, ' ');


    // Go backwards and move a char to position spaceLeft * 2 
    for(uint32_t i = origSize - 1; i > 0 && spacesLeft; --i) {
        // Insert space-substitution in the new place
        uint32_t newPosition = i + spacesLeft*2; 
        if (url[i] == ' ') { 
            --spacesLeft;
            url[newPosition] = '0'; 
            url[newPosition-1] = '2';
            url[newPosition-2] = '%';
        } else { // Move char to the new place
            url[newPosition] = url[i];
        }
    }
}

int main() {

    string URL;

    cout << "enter the URL:\n";
    getline(cin >> ws, URL);
    cout << "You entered: " << URL << endl;

    URLify(URL);

    cout << "URLified: " <<  URL << endl;
    return 0;
}
