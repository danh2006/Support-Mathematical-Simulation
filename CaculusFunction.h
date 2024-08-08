
template<class T = double> class CaculusFunction{
public:
   CaculusFunction(): vec.resize(1), _var_name("x"){}
   CaculusFunction(H&& value);
   CaculusFunction operator=(H&& value);
   CaculusFunction operator=(const H&& value);

   CaculusFunction& operator+(H&& value);
   CaculusFunction& operator+=(H&& value);
   CaculusFunction& operator-(H&& value);
   CaculusFunction& operator-=(H&& value);
   CaculusFunction& operator*(H&& value);
   CaculusFunction& operator*=(H&& value);
   CaculusFunction& operator/(H&& value);
   CaculusFunction& operator/=(H&& value);

   bool operator==(H&& value);
   bool operator!=(H&& value);
    
   // Iterator 
   auto begin();
   const auto begin()const; 
   auto end();
   const auto end()const;
   auto rbegin();
   const auto rbegin()const; 
   auto rend();
   const auto rend()const;
    
   bool empty()const;
   size_t size();
   void clear();
   size_t find(const double value);
   const size_t find(const double value) const;
   void erase(vector<double>::iterator it);
   void erase(const double value);
   void insert(vector<double>::iterator it, const double value);
   double at(const size_t id);
   const double at(const size_t id) const;
   double operator[](const size_t id);
   const double operator[](const size_t id)const;


   CaculusFunction& remove_coefficient();
   CaculusFunction& intergal();
   CaculusFunction& grad();
   string* var_name();
   double lim(double value, bool greater = true);
   double with_value(double value);
   double global_min();
   double global_max();
   
   template<class Range, class Step> 
   double min_range(Range begin, Range end, Step step = 0.05);
   template<class Range, class Step> 
   double max_range(Range begin, Range end, Step step = 0.05);

   // tim he so C sau khi nguyen ham ham so
   // value o day la gia tri cua ca ham so sau khi nguyen ham,
   // x la gia tri thay vao cua ham so nguyen ham 
   double C(const double x, const double value); 

   // read-write function 
   friend void read(CaculusFunction& value);
   friend void print(const CaculusFunction value);

   template<class Function> 
   friend double calc_grad(Function&& func, const double x){
      const double eps = 1e-6;
      return (double)(func(x+eps)-func(x-eps))/(2*eps);
   }

private:
   vector<double> Vec;
   string _var_name;
   //a single number
   CaculusFunction convert(char c);
   CaculusFunction convert(const T num);

   // list 
   CaculusFunction convert(const char* c);
   CaculusFunction convert(const string s)
   CaculusFunction convert(const CaculusFunction other);
   CaculusFunction convert(const vector<T> vec);
   CaculusFunction convert(initializer_list<T> List);
}

calc_grad(f, 2)