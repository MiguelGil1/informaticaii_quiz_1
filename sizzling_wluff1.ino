/*
 Documentacion:
 Programa que pide al usuario un numero entero (int) N  e imprime el resultado de la suma de
 todos sus digitos elevados a si mismos.
 Ejemplo de uso:
 Siel usuario ingresa 1223 el seultado de lqa suma seria:
 1^1 + 2^2 + + 2^2 + 3^3 = 36
 Acotamiento de variables:
 Debemos de tener en cuenta que todas las variables utilizadas
 en el programa son de tipo int (entero), el cual tiene un  tamano de 
 2 bytes, por lo cual el valor de todas las variables deben ser menores o iguales a -32768
 o mayores o iguales a 32767 de lo contrario no se asegura
 un resultadocorrecto
 -32768 <= variable <= 32767
*/
int main(){
  init();
  //SETUP
  int n,suma = 0, numero, digito, mayor = 0, cont_mayor = 0;
  Serial.begin(9600);
  //FIN SETUP
  
  Serial.print("Ingrese un numero entero: ");
  while(Serial.available() == 0);
  n = Serial.parseInt();
  Serial.println(n);
  while (n > 0){
    numero = 1;
    digito = n % 10;
    if(digito > mayor){
      //Evalua si el digito actual es mayor al almacenado
      //en la variable  mayor, si lo es, reinicia la variable cont_mayor
      //y la iguala a 1 e iguala la variable mayor igual al digito actual
      cont_mayor = 1;
      mayor = digito;
    }else if(mayor == digito){
      //Si la condicion actual no se cumple, evalua si el digito actual
      //Es igual al almacenado en la variable mayor. si es cierto,
      //incrementa en 1 unidad la variable cont_mayor
      cont_mayor++;
    }
    //El sigueinte for itera desde i = 0 hasta el i < digito
    //En el se encuentra otro for anidado en el cual se calcula la potencia
    //Del digito actual por medio de sumas iterativas
    for(int i = 0; i < digito; i++){
      int s = 0;
      for(int j = 0; j < numero; j++){
        s = s + digito;
      }
      numero = s;
    }
    suma += numero;
    n = n / 10;//Divide el numero ingresado por el usuario entre 3 para poder hallar el siguiente digito
  }
  Serial.print("El resultado de la suma es: ");
  Serial.println(suma);
  if(cont_mayor == 1){
    Serial.print("El digito mayor encontrado es el ");
    Serial.print(mayor);
    Serial.print(" que aparece ");
    Serial.print(cont_mayor);
    Serial.print(" vez");
  }else{
    Serial.print("El digito mayor encontrado es el ");
    Serial.print(mayor);
    Serial.print(" que aparece ");
    Serial.print(cont_mayor);
    Serial.print(" veces");
  }
  while(true){
    // LOOP
    // FIN LOOP
  }
  return 0;
}