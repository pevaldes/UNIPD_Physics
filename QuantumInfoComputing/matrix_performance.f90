program matrixPerformance

    integer, allocatable :: seed(:)
    integer :: nseed

    integer, parameter :: dimA1 = 3, dimA2 = 3, dimB1 = 3, dimB2 = 3
    integer, dimension(dimA1, dimA2) ::  matrix1
    integer, dimension(dimB1, dimB2) :: matrix2
    integer, dimension(size(matrix1, dim=1), size(matrix2, dim=2)) :: matrix_mult ! Result of matrix multiplication with the proper size
    real    :: a, b
    integer :: rand_integer1, rand_integer2
    integer :: entries_sum
    real*4 :: t1_i, t1_f, T1, t2_i, t2_f, T2

    !Set a seed for reproducible calculations
    call random_seed(size=nseed)
    allocate(seed(nseed))
    seed=1234
    call random_seed(put=seed)
    
    ! Testing Performance
    
    ! Build matrices with random entries
    do i=1,size(matrix1, dim=1)
        do j=1,size(matrix1, dim=1)
            call random_number(a)
            rand_integer1 = floor(10*a)
            matrix1(i,j) = rand_integer1
        end do
    end do

    print *, ''
    do i=1,size(matrix2, dim=1)
        do j=1,size(matrix2, dim=1)
            call random_number(b)
            rand_integer2 = floor(10*b)
            matrix2(i,j) = rand_integer2
        end do
    end do

    print *, 'Matrix 1: '

    do i=1,size(matrix1, dim=1)
        write(*,*)(matrix1(i,j),j=1,size(matrix1, dim=2))
    end do 

    print *, ''
    print *, 'Matrix 2'

    do i=1,size(matrix2, dim=1)
        write(*,*)(matrix2(i,j),j=1,size(matrix2, dim=2))
    end do 

    print *, ''

    ! Method 1 for matrix-matrix multiplication
    call cpu_time(t1_i)
    do i=1,size(matrix1, dim=1)
        do j=1,size(matrix2, dim=2)
            entries_sum = 0
            do k=1,size(matrix1, dim=2)
                entries_sum = entries_sum + matrix1(i,k) * matrix2(k,j)
            end do
            matrix_mult(i,j) = entries_sum
        end do
    end do
    call cpu_time(t1_f)

    print *, 'Matrix-Matrxix multiplication'
    !Result method 1
    do i=1,size(matrix_mult, dim=1)
        write(*,*)(matrix_mult(i,j),j=1,size(matrix_mult, dim=2))
    end do 

    print *, ''
    T1 = t1_f - t1_i
    print *, 'Running time method 1: ', T1, ' sec'
    print *, ''
    
    !Method 2 for matrix-matrix multplication
    

end program matrixPerformance