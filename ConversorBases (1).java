package prueba;

public class ConversorBases {
    
    /**
     * Conversor de Bases es un programa que permite la introducción de un número 
     * en cualquier base, para devolver el mismo número expresado en otra base.
     * Las bases soportadas van de BINARIO (2) a HEXADECIMAL (16).
     * @autor FERRARI DESTÉFFANIZ, Juan Ignacio ; LOUBET, Nicolás Alfredo
     * @since JDK 1.5 (java.util.Scanner class)
     */
    
    private static java.util.Scanner scanner;
    private static final byte NUM_DECIMALES= 20;
    
    /**
     * Método inicial : main.
     * @param args String[] que recibe desde consola.
     */
    public static void main(String[] args) {
        int base_origen;
        int base_destino;
        String numero;
        
        scanner= new java.util.Scanner(System.in);
        
        do {
            System.out.print("Ingrese la base original del número: ");
            base_origen= scanner.nextInt();
            if(base_origen < 2 || base_origen > 16) {
                System.out.println("La base debe estar entre 2 y 16!");
            }
        } while(base_origen < 2 || base_origen > 16);
        do {
            System.out.print("Ingrese el número en base " + base_origen + " (Caracteres permitidos: " + getCaracteres(base_origen) + "): ");
            numero= scanner.next();
            if(!esValido(numero, base_origen)) {
                System.out.println("El número ingresado no pertenece a la base " + base_origen + "!");
            }
        } while(!esValido(numero, base_origen));
        do {
            System.out.print("Ingrese la base destino del número: ");
            base_destino= scanner.nextInt();
            if(base_destino < 2 || base_destino > 16) {
                System.out.println("La base debe estar entre 2 y 16!");
            }
        } while(base_destino < 2 || base_destino > 16);
        System.out.println();
        System.out.println("El número resultante es: " + convertirDecimalAX(convertirXADecimal(numero, base_origen), base_destino) + "(" + base_destino + ")");
    }
    
    /**
     * Método para obtener los caracteres permitidos de una base de numeración.
     * @param base La base de numeración.
     * @return String: Caracteres permitidos en esa base, separados por ", ".
     */
    public static String getCaracteres(int base) {
        String cadena= "0";
        
        for(int i= 1; i < base; i++) {
            cadena= cadena + ", " + getValue(i);
        }
        return cadena;
    }

    /**
     * Método para convertir un valor numérico en un caracter equivalente.
     * Devuelve un String por comodidad, pero su longitud es de 1 caracter.
     * A= 10, B= 11, C= 12, ..., F= 15.
     * @param num El número que se desea convertir a un caracter.
     * @return String: El valor del parámetro.
     */
    public static String getValue(int num) {
        String output= "";
        
        if(num < 10) {
            output= "" + num;
        } else
        if(num == 10){
            output= "A";
        } else
        if(num == 11){
            output= "B";
        } else
        if(num == 12){
            output= "C";
        } else
        if(num == 13){
            output= "D";
        } else
        if(num == 14){
            output= "E";
        } else
        if(num == 15){
            output= "F";
        }
        return(output);
    }

    /**
     * Método para convertir un caracter en un valor numérico equivalente.
     * A= 10, B= 11, C= 12, ..., F= 15.
     * @param numero El caracter que se desea convertir a entero.
     * @return int: El valor numérico del parámetro.
     */
    private static int getValue(String numero) {
        int output;
        
        switch(numero.toLowerCase()) {
            case "a":
                output= 10;
                break;
            case "b":
                output= 11;
                break;
            case "c":
                output= 12;
                break;
            case "d":
                output= 13;
                break;
            case "e":
                output= 14;
                break;
            case "f":
                output= 15;
                break;
            case ".": case ",":
                output= 0;
                break;
            default:
                output= Integer.parseInt(numero);
        }
        return(output);
    }

    /**
     * Método para convertir un número en cualquier base a decimal.
     * @param numero Número inicial en base <base_inicial>.
     * @param base_inicial La base de <numero>.
     * @return String: El número en base 10 equivalente a <numero> en base <base_inicial>.
     */
    private static String convertirXADecimal(String numero, int base_inicial) {
        String output;
        double total= 0;
        String enteronumero;
        String fracionalnumero= "";
        
        if(numero.indexOf('.') == -1 && numero.indexOf(',') == -1) {
            enteronumero= numero + " ";
        } else if(numero.indexOf(',')==-1) {
            enteronumero= numero.substring(0,numero.indexOf('.')) + " ";
            fracionalnumero= numero.substring(numero.indexOf('.')+1) + " ";
        } else {
            enteronumero= numero.substring(0,numero.indexOf(',')) + " ";
            fracionalnumero= numero.substring(numero.indexOf(',')+1) + " ";
        }
        for(int contador= enteronumero.length()-1; enteronumero.length() > 1; contador--) {
            total= total+getValue(enteronumero.charAt(0) + "")*Math.pow(base_inicial, contador-1);
            enteronumero= enteronumero.substring(1);
        }
        for(int contadorbis=(fracionalnumero.length()+1-fracionalnumero.length())*-1;fracionalnumero.length()>1;contadorbis--){
            total= total+getValue(fracionalnumero.charAt(0) + "")*Math.pow(base_inicial, contadorbis);
            fracionalnumero= fracionalnumero.substring(1);
        }
        output= total + "";
        return(output);
    }

    /**
     * Método para convertir un número decimal en otro equivalente en cualquier base.
     * @param numero Número inicial en base 10.
     * @param base La base final del valor de retorno.
     * @return String: El número en base <base> equivalente a <numero> en base 10.
     */
    private static String convertirDecimalAX(String numero, int base) {
        String output_entero= "";
        String output_decimal= "";
        String output;
        int entero;
        double decimal;
        int posicion_coma= 0;
        int repeticiones= 0;
        
        for(int i= 0; i < numero.length(); i++) {
            if(numero.charAt(i) == ',' || numero.charAt(i) == '.') {
                posicion_coma= i;
                i= numero.length();
            }
        }
        if(posicion_coma == 0) {
            posicion_coma= numero.length();
        }
        //Parte entera
        entero= Integer.parseInt(numero.substring(0, posicion_coma));
        while(entero >= base) {
            output_entero= (entero % base) + output_entero;
            entero= ((int) (entero / base));
        }
        output_entero= entero + output_entero;
        //Parte decimal
        if(posicion_coma < numero.length()) {
            decimal= Double.parseDouble("0." + (numero.substring(posicion_coma+1, numero.length())));
            while((decimal - ((int) decimal)) > 0) {
                decimal*= base;
                output_decimal= output_decimal + ((int) decimal);
                decimal-= (int) decimal;
                repeticiones++;
                if(repeticiones > NUM_DECIMALES) {
                    decimal= 0;
                }
            }
        }
        output= output_entero + (output_decimal.equals("")?"":"," + output_decimal);
        return(output);
    }

    /**
     * Método para determinar si un número puede pertenecer a una base determinada.
     * @param numero El número que se desea controlar.
     * @param base La base con la que se desea comparar
     * @return boolean: TRUE si <numero> pertenece a la base <base>. FALSE en caso contrario.
     */
    private static boolean esValido(String numero, int base) {
        boolean output= true;
        
        for(int i= 0; i < numero.length(); i++) {
            if(getValue("" + numero.charAt(i)) >= base) {
                output= false;
                i= numero.length();
            }
        }
        return output;
    }

}
