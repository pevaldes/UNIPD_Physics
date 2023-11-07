program matrixPerformance

    integer, allocatable :: seed(:)
    integer :: nseed

    integer :: io, io1, io2, io3


    real, parameter :: nn = log(1900.0)/log(2.0) !First number is to define the dimension of the matrix
    real, parameter :: N = nn
    integer, parameter :: dimA1 = nint(2.0**N), dimA2 = nint(2.0**N), dimB1 = nint(2.0**N), dimB2 = nint(2.0**N)
    integer, dimension(dimA1, dimA2) ::  matrix1
    integer, dimension(dimB1, dimB2) :: matrix2
    integer, dimension(size(matrix1, dim=1), size(matrix2, dim=2)) :: matrix_mult, matrix_mult2, fortran_mult ! Result of matrix multiplication with the proper size
    real    :: a, b
    integer :: rand_integer1, rand_integer2
    integer :: entries_sum
    real*4 :: t1_i, t1_f, T1, t2_i, t2_f, T2, t3_i, t3_f, T3

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

    !print *, 'Matrix 1: '

    !do i=1,size(matrix1, dim=1)
     !   write(*,*)(matrix1(i,j),j=1,size(matrix1, dim=2))
    !end do 

    !print *, ''
    !print *, 'Matrix 2'

    !do i=1,size(matrix2, dim=1)
     !   write(*,*)(matrix2(i,j),j=1,size(matrix2, dim=2))
    !end do 

    !print *, ''

    ! Method 1 for matrix-matrix multiplication (row selection)
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
    !do i=1,size(matrix_mult, dim=1)
     !   write(*,*)(matrix_mult(i,j),j=1,size(matrix_mult, dim=2))
    !end do 

    print *, ''
    T1 = t1_f - t1_i
    print *, 'Running time method 1: ', T1, ' sec'
    print *, ''
    
    !Method 2 for matrix-matrix multplication (column selection)
    call cpu_time(t2_i)
    do j=1,size(matrix1, dim=1)
        do i=1,size(matrix2, dim=2)
            entries_sum = 0
            do k=1,size(matrix1, dim=2)
                entries_sum = entries_sum + matrix1(i,k) * matrix2(k,j)
            end do
            matrix_mult2(i,j) = entries_sum
        end do
    end do
    call cpu_time(t2_f)


    !Result method 2
    !do i=1,size(matrix_mult2, dim=1)
     !   write(*,*)(matrix_mult2(i,j),j=1,size(matrix_mult2, dim=2))
    !end do 

    T2 = t2_f - t2_i
    print *, 'Running time method 2: ', T2, 'sec'
    print *, ''

    !Fortran intrinsic matrix matrix multiplication
    print *, 'Fotran matrix multiplication function'
    call cpu_time(t3_i)
    fortran_mult =  matmul(matrix1,matrix2)
    call cpu_time(t3_f)

    !do i=1,size(fortran_mult, dim=1)
     !   write(*,*)(fortran_mult(i,j),j=1,size(fortran_mult, dim=2))
    !end do

    print *,''

    T3 = t3_f - t3_i
    print*, 'Running time fortran method: ', T3, 'sec'
    print *, ''

    !Write times in txt file to analyse later
    open(newunit=io, file="data_matrixPerformance_Ofast.txt", position='append', action='write')
    write(io,*)'Method 1: ', T1, ' sec; ', N
    write(io,*)'Method 2: ', T2, ' sec; ', N
    write(io,*)'Fortran method: ', T3, 'sec; ', N
    close(io)

    !Write the matrix producto in a txt file. Needed when using flags
    open(newunit=io1, file="result_method1.txt", action='write')
    do i=1,size(matrix_mult, dim=1)
        write(io1,*)(matrix_mult(i,j),j=1,size(matrix_mult, dim=2))
    end do
    close(io1)

    open(newunit=io2, file="result_method2.txt", action='write')
    do i=1,size(matrix_mult2, dim=1)
        write(io2,*)(matrix_mult2(i,j),j=1,size(matrix_mult2, dim=2))
    end do
    close(io2)

    open(newunit=io3, file="result_fortran.txt", action='write')
    do i=1,size(fortran_mult, dim=1)
        write(io3,*)(fortran_mult(i,j),j=1,size(fortran_mult, dim=2))
    end do
    close(io3)

end program matrixPerformance