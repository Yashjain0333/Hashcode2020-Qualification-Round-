# Hashcode 2020 solution (Qualification round)
This is my solution for the [Google Hashcode 2020](https://codingcompetitions.withgoogle.com/hashcode) qualification round problem with libraries and books. Although I did not participate in the round but rather did this problem for practice.

<p align="center">
<img src="/Images/hashcode.jpg" alt="Hashcode Logo" width="500"/>
</p>


## Results

| File  | Score |
| ------------- | ------------- |
| a_example ([input](Input/a.txt) \| [output](Output/a(out).txt)) | 21 |
| b_read_on ([input](Input/b.txt) \| [output](Output/b(out).txt)) | 5,822,900 |
| c_incunabula ([input](Input/c.txt) \| [output](Output/c(out).txt)) | 5,483,590 |
| d_tough_choices ([input](Input/d.txt) \| [output](Output/d(out).txt)) | 5,028,530 |
| e_so_many_books ([input](Input/e.txt) \| [output](Output/e(out).txt)) | 5,399,965 |
| f_libraries_of_the_world ([input](Input/f.txt) \| [output](Output/f(out).txt)) | 5,322,929 |
| **Total** | **27,057,935** |


## The problem

You can find the pdf with the problem [here](hashcode_2020_online_qualification_round.pdf).

<img src="/Images/hashcode_2020_problem.png" alt="Hashcode 2020 problem" width="500"/>


## My solution

The code for the solution is in [main.cpp](main.cpp). My approach was a greedy algorithm.

The solution follows these steps:

1. Read the input
2. Proceed by finding the best library that we can schudule next for the signup process. 
   1. This involves sorting the books in a particular library according to the score that it can provide.
   2. Then after calculating the score, add some penulty for the signup time the library takes.
   
   <p align="center">
   <img src="https://latex.codecogs.com/svg.latex?\Large&space;library\_score=sum\_of\_all\_books-signup*penulty"
   </p>
   
      ### Penulty for Signup time

      | File  | Penulty |
      | ------------- | ------------- |
      | a_example | 1000 |
      | b_read_on | 1000 |
      | c_incunabula | 1100 |
      | d_tough_choices | 1100 |
      | e_so_many_books | 15000 |
      | f_libraries_of_the_world | 3000 |

5. Create the output.
6. Also calculate the score.
