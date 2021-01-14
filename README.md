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
2. Calculate a heuristic score for each library with this formula:

   
   <p align="center">
   <img src="https://latex.codecogs.com/svg.latex?\Large&space;library\_score=\frac{library\_books\_score}{library\_signup\_days}" title="library_score = library_books_score / library_signup_days" />
   </p>  

   where library_books_score is calculated like this:

   1. Calculate available days for this library:

   <p align="center">
   <img src="https://latex.codecogs.com/svg.latex?\Large&space;library\_available\_days=all\_days-library\_signup\_days" title="library_available_days = all_days - library_signup_days" />
   </p>

   2. Count how many books can be scanned in these days:

   <p align="center">
   <img src="https://latex.codecogs.com/svg.latex?\Large&space;k=library\_available\_days&space;\times&space;library\_maximum\_books\_scanned\_per\_day" title="k = library_available_days * library_maximum_books_scanned_per_day" />
   </p>

   3. Get the top k books according to their score and sum their scores. This is the *library_books_score*.

3. Sort libraries according to their score
4. For every library in sorted order:
   1. Count how many books from this library (k) can be scanned, like in steps 2i and 2ii, but now take into account the number of signup days from the previous libraries. So if the previous libraries have taken *d* total days for the signup, then the formula from the step 2i becomes:
   <p align="center">
   <img src="https://latex.codecogs.com/svg.latex?\Large&space;library\_available\_days=all\_days-library\_signup\_days-d" title="library_available_days = all_days - library_signup_days - d" />
   </p>
   
   2. From the books of this library, except the books that have already been scanned from the previous libraries, get the top k books according to their score and scan them.

5. Create the output.
6. Also calculate the score.
