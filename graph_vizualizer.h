#ifndef GRAPH_VIZUALIZER_H
#define START 115
#define BRAKE 98
#define PAUSE 112
#define QUIT 113
#define GRAPH_VIZUALIZER_H
#endif // GRAPH_VIZUALIZER_H

#pragma once

#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstdarg>
#include <chrono>
#include <thread>
#include <QVector>
#include <fstream>

const std::chrono::microseconds menu_timeout(50);

class graph_vizualizer {
public:
    explicit graph_vizualizer() = default;
    explicit graph_vizualizer(double a, double b, double c, double f, double t, double s):A_(a), B_(b), C_(c), from_(f), to_(t), step_(s) {};

    std::vector<std::string> get_core_formulas();
    std::vector<std::pair<double, double>> get_res();
    bool get_start();
    bool get_brake();
    bool get_pause();
    bool get_quit();
    size_t get_form_num();
    double get_from();
    double get_to();
    double get_step();

    void set_start(bool s);
    void set_brake(bool b);
    void set_pause(bool p);
    void set_quit(bool q);
    void set_formula(size_t f);
    void set_a(double a);
    void set_b(double b);
    void set_c(double c);
    void set_from(double f);
    void set_to(double t);
    void set_step(double s);
    void set_parametrs();

    void clear_res_points();
    void async_menu();
    double get_percent();
    void main_menu_loop();
    void save_result();
private:
    //interface
    char menu_pos_ = '0';
    bool brake_ = false;
    bool pause_ = false;
    bool start_ = false;
    bool quit_ = false;
    bool info_ = false;
    int menu_switcher_ = 0;
    //core
    std::vector<std::string> core_formulas_{
        "f(x) = A * (x * x) + B * x + C",
        "f(x) = A * sin(x) + B * cos(C * x)",
        "f(x) = A * log(B * x)",
        "f(x) = A / (sin(x * x) * B)",
        "f(x) = 4 * sin(x / 2)"
    };
    //data
    double percent_ = 0.0;
    size_t formula_num_ = 0;
    double A_ = 0.0;
    double B_ = 0.0;
    double C_ = 0.0;
    double from_ = 0.0;
    double to_ = 0.0;
    double step_ = 0.0;
    std::pair<double, double> x_y_ = std::make_pair(0.0, 0.0);
    std::vector<std::pair<double, double>> res_ {};
};

