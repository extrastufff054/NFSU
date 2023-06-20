// // Prime or not with user input also all prime numbers between 1 to 100

// using System;
// namespace Prime_Num2
// {
//         class Prime_Num 
//     {
//         static void Main()
//         {
//             Console.Write("Enter a number :");
//             int x = int.Parse(Console.ReadLine());
//             if(x % 2 == 0)
//             {
//                 Console.WriteLine("Number is not prime");
//             }
//             else
//             {
//                 Console.WriteLine("Number is prime");
//             }

//             Console.WriteLine("Prime numbers between 1 to 100 are :");
//             for (int i = 1; i <= 100; i++)
//             {
//                 int count = 0;
//                 for (int j = 2; j <= i / 2; j++)
//                 {
//                     if (i % j == 0)
//                     {
//                         count++;
//                         break;
//                     }
//                 }
//                 if (count == 0 && i != 1)
//                     Console.WriteLine(i + " ");
//             }
//         }
//     }

// }