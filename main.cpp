#include <iostream>
#include <random>
#include "instance.hpp"
#include "mcmc.hpp"
using namespace std;

int main(){
    int n = 100, m = 500, T = 1000;
    int pace = T/100;
    double beta = 0, delta = 0.01;
    default_random_engine g;
    g.seed('E'*'n'*'g'*'u'+'e'*'r'*'r'*'a'+'n'*'d');
    instance problem(n, m, g);
    MCMC solve(n, problem.get_points(), beta, g);

    cout << "original is:" << endl;
    for(double x:problem.get_model())
        cout << x << " ";
    cout << endl;

    int p,q;
    cout << "starting vector is:" << endl;
    for(double x:solve.get_state())
        cout << x << " ";
    cout << endl;
    solve.error_rate(p,q);
    cout << p << "/" << q << endl;

    solve.advance_state(T, g, pace, delta);
    cout << "found vector is:" << endl;
    for(double x:solve.get_state())
        cout << x << " ";
    cout << endl;
    solve.error_rate(p,q);
    cout << p << "/" << q << endl;
	return 0;
}
