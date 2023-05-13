#ifndef _URL_HPP
#define _URL_HPP

#include <iostream>
#include <string>

using namespace std;

class Url
{
private:
    string esquema;
    string dominio;
    int porta;
    string caminho;
    string _url;

public:
    Url(const string &esquema, const string &dominio, int porta, const string &caminho)
        : esquema(esquema), dominio(dominio), porta(porta), caminho(caminho) {}

    Url(const std::string &url) : _url(url) {}

    Url(const Url &obj);

    const string &getEsquema() const { return esquema; }
    void setEsquema(const string &esquema) { this->esquema = esquema; }

    const string &getDominio() const { return dominio; }
    void setDominio(const string &dominio) { this->dominio = dominio; }

    int getPorta() const { return porta; }
    void setPorta(int porta) { this->porta = porta; }

    const string &getCaminho() const { return caminho; }
    void setCaminho(const string &caminho) { this->caminho = caminho; }

    void printUrl();
    void print_Url();
};

Url operator""_url(const char *url, size_t size)
{
    return Url(string(url, size));
}

Url::Url(const Url &obj)
{
    esquema = obj.esquema;
    dominio = obj.dominio;
    porta = obj.porta;
    caminho = obj.caminho;
}

void Url::printUrl()
{
    cout << getEsquema() << "://";
    cout << getDominio() << ":" << getPorta() << "/";
    cout << getCaminho();
}

void Url::print_Url()
{
    cout << _url;
}

#endif