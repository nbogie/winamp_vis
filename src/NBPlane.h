
// Plane

class NBPlane {
  
   public:
      NBVector n;
      float k;
  
      NBPlane();
  
      NBPlane(const NBVector & _n, float _k);
  
      float DotProd(const NBVector & v);
  
};

  inline float NBPlane::DotProd(const NBVector & v)
  {
    return v.DotProd(n) - k;
  }
  inline NBPlane(const NBVector & _n, float _k)
  {
    n = _n;
    k = _k;
  }
  
