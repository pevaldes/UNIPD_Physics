program matrixPerformance

    integer*2   ::  matrix3(5,5), matrix2(4,4)
    real    :: a
    integer :: rand_integer

    ! Testin Performance

    !do i=1,4
     !   matrix1(i,i) = 1
    !end do

    call random_number(a)

    do i=1,4
        write(*,*)(matrix2(i,j),j=1,4)
    end do 

    print *, ''

    do i=1,5
        write(*,*)(matrix3(i,j),j=1,5)
    end do 

    print *, ''
    print *, a 

    rand_integer = floor(100*a)
    print *, rand_integer


end program matrixPerformance