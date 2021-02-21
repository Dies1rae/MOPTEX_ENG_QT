#include "graph_vizualizer.h"

#include <future>
#include <thread>
#include <conio.h>
#include <mutex>
#include <atomic>

using namespace std;


int menu_switcher() {
    int menu = _getch();
    return menu;
}

void graph_vizualizer::save_result(){
    std::string dst_name = ".\\";
    if(!this->res_.empty()){
        dst_name += std::to_string(this->formula_num_);
        dst_name += "_" + std::to_string((this->res_[0].first + this->res_[0].second));
    } else {
        dst_name += "empty";
    }

    dst_name += ".txt";
    ofstream out(dst_name);
    out << "        X   |   Y   \n";
    for(size_t ptr = 0; ptr < this->res_.size(); ptr ++){
        out << "    " << this->res_[ptr].first << "    " << this->res_[ptr].second << "   \n";
    }
    out.close();
}

std::vector<std::string> graph_vizualizer::get_core_formulas(){
    return this->core_formulas_;
}

std::vector<std::pair<double, double>> graph_vizualizer::get_res(){
    return this->res_;
}

double graph_vizualizer::get_percent() {
    this->percent_ = ((this->res_.size() - 1)/ ((this->to_ - this->from_) / this->step_)) * 100;
    return this->percent_;
}

void graph_vizualizer::async_menu() {
    auto future = std::async(menu_switcher);
    if (future.wait_for(menu_timeout) == std::future_status::ready) {
        this->menu_switcher_ = future.get();
    }
}

size_t graph_vizualizer::get_form_num(){
    return this->formula_num_;
}

bool graph_vizualizer::get_start(){
    return this->start_;
}
bool graph_vizualizer::get_brake(){
    return this->brake_;
}
bool graph_vizualizer::get_pause(){
    return this->pause_;
}
bool graph_vizualizer::get_quit(){
    return this->quit_;
}

double graph_vizualizer::get_from(){
    return this->from_;
}

double graph_vizualizer::get_to(){
    return this->to_;
}

double graph_vizualizer::get_step(){
    return this->step_;
}

void graph_vizualizer::set_a(double a){
    this->A_ = a;
}
void graph_vizualizer::set_b(double b){
    this->B_ = b;
}
void graph_vizualizer::set_c(double c){
    this->C_ = c;
}
void graph_vizualizer::set_from(double f){
    this->from_ = f;
}
void graph_vizualizer::set_to(double t){
    this->to_ = t;
}
void graph_vizualizer::set_step(double s){
    this->step_ = s;
}

void graph_vizualizer::set_formula(size_t f){
    this->formula_num_ = f;
}

void graph_vizualizer::set_parametrs() {
    std::cout << "Please set parametrs for field A B C and FROM TO STEP" << std::endl;
    std::cin >> this->A_ >> this->B_ >> this->C_ >> this->from_ >> this->to_ >> this->step_;
}

void graph_vizualizer::set_start(bool s){
    this->start_ = s;
}
void graph_vizualizer::set_brake(bool b){
    this->brake_ = b;
}
void graph_vizualizer::set_pause(bool p){
    this->pause_ = p;
}
void graph_vizualizer::set_quit(bool q){
    this->quit_ = q;
}

void graph_vizualizer::clear_res_points(){
    this->res_.clear();
}

void graph_vizualizer::main_menu_loop() {
    if (this->start_) {
        this->percent_ = 0;

        switch (this->formula_num_) {
        case 1:
            try {
                for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
                    this->x_y_.second = (this->A_ * std::pow(this->x_y_.first, 2)) + (this->B_ * this->x_y_.first) + this->C_;
                    this->res_.push_back(this->x_y_);
                }
            }
            catch (...) {
                std::cerr << "Some data error" << std::endl;
            } break;
        case 2:
            try {
                for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
                    this->x_y_.second = (this->A_ * sin(this->x_y_.first)) + (this->B_ * cos(this->x_y_.first * this->C_));
                    this->res_.push_back(this->x_y_);
                }
            }
            catch (...) {
                std::cerr << "Some data error" << std::endl;
            } break;
        case 3:
            try {
                for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
                    this->x_y_.second = this->A_ * log(this->B_ * this->x_y_.first);
                    this->res_.push_back(this->x_y_);
                }
            }
            catch (...) {
                std::cerr << "Some data error" << std::endl;
            } break;
        case 4:
            try {
                for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
                    this->x_y_.second = this->A_ / ((sin(std::pow(this->x_y_.first, 2))) * this->B_);
                    this->res_.push_back(this->x_y_);
                }
            }
            catch (...) {
                std::cerr << "Some data error" << std::endl;
            } break;
        case 5:
            try {
                for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
                    this->x_y_.second = 4 * sin(this->x_y_.first / 2);
                    this->res_.push_back(this->x_y_);
                }
            }
            catch (...) {
                std::cerr << "Some data error" << std::endl;
            } break;
        default:
            break;
        }
    }
}
