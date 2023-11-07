program numberPrecision
    implicit none
    ! Integer and real numbers have a finite precision. 

    ! (a) Sum integer
    integer*2   ::  int2, one2, sum_integer2
    integer*4   ::  int4, one4, sum_integer4

    real*4    :: pi_single, ten32_single, sq_root_single, ten21_single, result_single
    real*8    :: pi_double, ten32_double, sq_root_double, ten21_double, result_double

    ! int2 = 2000000 gives an overflow error because, for INTEGER*2, the space saved is for 2 bytes = 16 bits. 
    ! Which means that the maximum integer value stored is around 2**15 - 1 = 32767 << 2000000
    one2 = 1
    int4 = 2000000
    one4 = 1

    sum_integer2 = int2 + one2
    sum_integer4 = int4 + one4

    print *, 'Sum of integers'
    print *, 'Sum with INTEGER*2: Overflow error due to memory used at the declaration of int2.' 
    print *, 'Sum with INTEGER*4: ', sum_integer4
    print *, ''

    ! (b) Sum real

    pi_single = 4.0* atan(1.0_4)
    ten32_single = 10e32
    sq_root_single = sqrt(2.0)
    ten21_single = 10e21

    result_single = pi_single*ten32_single + sq_root_single*ten21_single

    pi_double = 4.0*atan(1.0_8)
    ten32_double = 10e32
    sq_root_double = sqrt(2.0)
    ten21_double = 10e21

    result_double = pi_double*ten32_double + sq_root_double*ten21_double

    print *, 'Sum of real numbers'
    print *, 'Sum with single precision: ', result_single
    print *, 'Sum with double precision: ', result_double
    ! print *, 'Pi: ', pi_double
    print *, ''

end program numberPrecision