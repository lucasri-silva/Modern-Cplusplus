#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <limits>

using namespace std;

double distancia(const pair<double, double> &orig, const pair<double, double> &dest)
{
    const auto R = 6371.0;
    // raio médio da Terra em Km
    const auto PI = 3.14159265; // constante PI
    decltype(orig.first) lat1_rad = orig.first * PI / 180.0;
    decltype(dest.first) lat2_rad = dest.first * PI / 180.0;
    decltype(orig.second) lon1_rad = orig.second * PI / 180.0;
    decltype(dest.second) lon2_rad = dest.second * PI / 180.0;
    double delta_lat = lat2_rad - lat1_rad;
    double delta_lon = lon2_rad - lon1_rad;
    double h = pow(sin(delta_lat / 2.0), 2.0) + cos(lat1_rad) * cos(lat2_rad) * pow(sin(delta_lon / 2.0), 2.0);
    double d = 2.0 * R * asin(pow(h, 0.5));
    return d;
}

auto& encontrar_menor_rota(map<string, vector<pair<double, double>>>& roteiros) {
    auto menor_distancia = numeric_limits<double>::max();
    pair<const string, vector<pair<double, double>>>* menor_rota = nullptr;
    
    for (auto& rota : roteiros) {
        auto distancia_rota = 0.0;
        auto origem = rota.second.begin();
        auto destino = ++rota.second.begin();
        double distancia_entre_pontos = 0.0;

        while (destino != rota.second.end())
        {
            distancia_entre_pontos = distancia(*origem, *destino);
            distancia_rota += distancia_entre_pontos;
            ++origem;
            ++destino;
        }

        if (distancia_rota < menor_distancia) {
            menor_distancia = distancia_rota;
            menor_rota = &rota;
        }
    }
    return *menor_rota;
}

int main()
{
    map<string, vector<pair<double, double>>> roteiros = {
        {
            "Estrada Real (MG)", {
                {-20.387058648132697, -43.50276489546531}, 
                {-21.110096884824063, -44.17400882389444}, 
                {-21.135392099979775, -44.26168702763076}, 
                {-23.219718444240385, -44.71541419792069}
            }
        },
        {
            "Caminho dos Príncipes (SC)", {
                {-26.45903196178978, -48.60186925577256}, 
                {-26.484889252846987, -49.08265794057286}, 
                {-26.301589093945626, -48.84812743826987}
            }
        },
        {
            "Serra Gaúcha (RS)", {
                {-29.165328627526332, -51.51579840115089}, 
                {-29.363757873430096, -50.81285822760663}, 
                {-29.377433015152402, -50.87455594332935}, 
                {-28.74764895560134, -50.065278332356094}
            }
        }
    };
    
    for (auto it = roteiros.begin(); it != roteiros.end(); ++it)
    {
        const string &nome = it->first;
        auto const &rota = it->second;
        auto distancia_total = 0.0;
        auto origem = rota.begin();
        auto destino = ++rota.begin();
        while (destino != rota.end())
        {
            double d = distancia(*origem, *destino);
            distancia_total += d;
            ++origem;
            ++destino;
        }
        cout << nome << ": " << distancia_total << " Km" << endl;
    }

    auto menorRota = encontrar_menor_rota(roteiros);
    cout << "Menor Rota é " << menorRota.first << endl;


    return 0;
}