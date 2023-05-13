#include "url.hpp"
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    string url = "https://github.com:443/lucasri-silva";
    regex url_regex(R"((\w+):\/\/([^:/]+)(?::(\d+))?([^?#]*))");

    /*
    (\w+): a capture group that matches one or more word characters (letters, digits, or underscores), representing the esquema value.
    :\/\/: matches the literal string ://.
    ([^:/]+): a capture group that matches one or more characters that are not a colon or a forward slash, representing the dominio value.
    (?::(\d+))?: an optional capture group that matches a colon followed by one or more digits, representing the porta value.
    ([^?#]*): a capture group that matches zero or more characters that are not a question mark or a hash, representing the caminho value.
    */

    string esquema;
    string dominio;
    int porta;
    string caminho;
    
    smatch url_match;
    if (regex_match(url, url_match, url_regex))
    {
        esquema = url_match[1];
        dominio = url_match[2];
        porta = stoi(url_match[3]);
        caminho = url_match[4].str().substr(1);
    }

    Url url1(esquema, dominio, porta, caminho);
    Url url2 = url1;
    
    url1.printUrl();
    cout << endl;
    url2.printUrl();

    url2.setDominio("wikipedia.org");
    url2.setCaminho("URL");
    cout << endl;

    cout << "\nApos modificar url2: " << endl;
    url1.printUrl();
    cout << endl;
    url2.printUrl();
    cout << endl;

    cout << "\nSobrecarga de operador de sufixo: " << endl;
    Url google = "https://www.google.com"_url;
    google.print_Url();
    cout << endl;

    return 0;
}