The final keyword in Java is used to restrict the user. The Java 'Final' keyword can be used
in many context. Final can be :
1) Variable
2) Method
3) Class

The final keyword can be applied with the variables, a final keyword that have no value it is
called 'blank final variable' ir 'uninitialized final variable'.
It can be initialized in the constructor only. The blank final variable can be static also 
which will be initialized in the static block only. 
  
1)JAVA FNIAL VARIABLE :
  If we make any varable final, we cannot change the value of final variable(It will be constant).
    
    For eg:- 
      
      class B.tech{
        
        final double class_strength=50;   //final variable
        void student()
        {
          class_strength=100;
        }
        
        public static void main(String args[]){
          B.tech obj=new B.tech();
          obj.run();
          
        }//end of main function
      }//end of class

OUTPUT:-
   //Compile time error
  
  
 Q) What is blank or uninitialized final variable??
  A final variable that is not initialized at the time of declaration.
  This can be initialized in a constructor.
