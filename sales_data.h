//
// Created by charlie01.chai on 2016/2/15.
//

#ifndef C_PRIMER_SALE_DATA_H
#define C_PRIMER_SALE_DATA_H
class Sales_data{
//  friend declarations for nomember Sales_data operations added
    friend Sales_data add(const Sales_data &,  const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    //other members and access specifiers as before
public:
//    typedef std::string::size_type pos;
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p): bookNO(s), units_sold(p), revenue(p*n) {}
    Sales_data(const std::string &s) : bookNO(s) {}
    Sales_data(std::istream&);
    std::string isbn() { return bookNO; }
    Sales_data &combine(const Sales_data&);

private:
    std::string bookNO;
    double arv_price() const {
        return units_sold ? revenue/units_sold : 0;
    }
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif //C_PRIMER_SALE_DATA_H
