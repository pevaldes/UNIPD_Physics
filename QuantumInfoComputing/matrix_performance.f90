program matrixPerformance

    real    ::  matrix1(4,4), matrix2(4,4)
    real*4    :: a

    ! Testin Performance

    do i=1,4
        matrix1(i,i) = 1
    end do

    call random_number(a)

    do i=1,4
        write(*,*)(matrix2(i,j),j=1,4)
    end do 

    print *, ''

    do i=1,4
        write(*,*)(matrix1(i,j),j=1,4)
    end do 

end program matrixPerformance