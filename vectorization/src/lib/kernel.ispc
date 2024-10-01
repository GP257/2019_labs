export void multISPC(uniform float a[], uniform float b[], uniform int n) {
  foreach (i = 0 ... n) {
    a[i]=a[i]*b[i];
  }
}
