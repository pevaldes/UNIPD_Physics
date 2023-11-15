module debuggger

contains 
    subroutine checkpoint(debug,msg)
        print *, msg
    end subroutine

end module
    
    
program main_debug
    use debuggger
    implicit none
    
    !test messages
    call checkpoint(debug = .TRUE., msg = "")

end program