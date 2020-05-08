gradient_descent<-function(f, x_0, tol, 
                           tol_backtracking, x_ast, p_ast, maxiter=30,
                           gf_symbolic=NULL){
    '
    Method of gradient descent to numerically approximate solution of min f.
    Args:
        f (fun): definition of function f.
        x_0 (double): vector of initial point for gradient descent method.
        tol (float): tolerance that will halt method. Controls norm of gradient of f.
        tol_backtracking (float): tolerance that will halt method. Controls value of line search by backtracking.
        x_ast (double): vector solution of min f, now its required that user knows the solution...
        p_ast (double): vector value of f(x_ast), now its required that user knows the solution...
        maxiter (int): maximum number of iterations.
        gf_symbolic (fun): definition of gradient of f. If given, no approximation is
                                     performed via finite differences.
    Returns:
        x (double): vector approximation of x_ast.
        iteration (int): number of iterations.
        Err_plot (double): vector array of absolute error between p_ast and f(x) with x approximation.
                          of x_ast. Useful for plotting.
        x_plot (double): vector array that containts in columns vector of approximations. Last column
                        contains x, approximation of solution. Useful for plotting.
    '
    iteration <- 1
    x <- x_0
    
    feval <- f(x)
    
    if (!is.null(gf_symbolic)){
        gfeval <- gf_symbolic(x)
    }else{
        gfeval <- gradient_approximation(f,x)
    }

    normgf <- Euclidian_norm(gfeval)
    
    Err_plot_aux <- vector("double",maxiter)
    Err_plot_aux[iteration] <- compute_error(p_ast,feval)
    
    Err <- compute_error(x_ast,x)
    n <- length(x)
    x_plot <- matrix(0,nrow=n,ncol=maxiter)
    x_plot[,iteration] <- x
    
    cat(sprintf("I\tNormagf\t\tError x_ast\tError p_ast\tline search\n"))
    cat(sprintf("%d\t%.2e\t%0.2e\t%0.2e\t%s\n",iteration,normgf,Err,Err_plot_aux[iteration],"---"))
    iteration<-iteration + 1
    while(normgf>tol && iteration < maxiter){
        dir_desc <- -gfeval
        der_direct <- sum(gfeval*dir_desc)
        t <- line_search_by_backtracking(f,dir_desc,x,der_direct)
        x <- x + t*dir_desc
        feval <- f(x)
        if (!is.null(gf_symbolic)){
            gfeval <- gf_symbolic(x)
        }else{
            gfeval <- gradient_approximation(f,x)
        }
        gfeval <- gradient_approximation(f,x)
        normgf <- Euclidian_norm(gfeval)
        Err_plot_aux[iteration] <- compute_error(p_ast,feval)
        x_plot[,iteration] <- x
        Err <- compute_error(x_ast,x)
        cat(sprintf("%d\t%.2e\t%0.2e\t%0.2e\t%0.2e\n",iteration,normgf,Err,Err_plot_aux[iteration],t))
        if (t<tol_backtracking){ #if t is less than tol_backtracking then we need to check the reason
            iter_salida <- iteration
            iteration <- maxiter - 1
        }
        iteration <- iteration + 1
    } #while
    cat(sprintf("Error of x with respect to x_ast: %.2e\n",Err))
    cat(sprintf("Approximate solution:"))
    print(x)
    cond <- Err_plot_aux > .Machine$double.eps*10**(-2)
    Err_plot <- Err_plot_aux[cond]
    if (iteration == maxiter && t < tol_backtracking){
        print("Backtracking value less than tol_backtracking, check approximation")
        iteration<-iter_salida
        x_plot <- x_plot[,1:iteration]
        iteration <- iteration -1
    }
    else{
        iteration <- iteration - 1
        x_plot <- x_plot[,1:iteration]
        }
   list(x,iteration,Err_plot,x_plot)
    
}    


coordinate_descent<-function(f, x_0, tol, 
                             tol_backtracking, 
                             x_ast, p_ast, maxiter=30,
                             gf_symbolic=NULL){
    '
    Method of coordinate descent to numerically approximate solution of min f.
    Args:
        f (fun): definition of function f.
        x_0 (double): vector of initial point for coordinate descent method.
        tol (float): tolerance that will halt method. Controls norm of gradient of f.
        tol_backtracking (float): tolerance that will halt method. Controls value of line search by backtracking.
        x_ast (double): vector solution of min f, now its required that user knows the solution...
        p_ast (double): vector value of f(x_ast), now its required that user knows the solution...
        maxiter (int): maximum number of iterations.
        gf_symbolic (fun): definition of gradient of f. If given, no approximation is
                                     performed via finite differences.
    Returns:
        x (double): vector approximation of x_ast.
        iteration (int): number of iterations.
        Err_plot (double): vector array of absolute error between p_ast and f(x) with x approximation.
                          of x_ast. Useful for plotting.
        x_plot (double): vector array that containts in columns vector of approximations. Last column
                        contains x, approximation of solution. Useful for plotting.
    '
    iteration <- 1
    x <- x_0
    
    feval <- f(x)

    if (!is.null(gf_symbolic)){
        gfeval <- gf_symbolic(x)
    }else{
        gfeval <- gradient_approximation(f,x)
    }

    normgf <- Euclidian_norm(gfeval)
    
    Err_plot_aux <- vector("double",maxiter)
    Err_plot_aux[iteration] <- compute_error(p_ast,feval)
    
    Err <- compute_error(x_ast,x)
    n <- length(x)
    x_plot <- matrix(0,nrow=n,ncol=maxiter)
    x_plot[,iteration] <- x
    
    cat(sprintf("I\tNormagf\t\tError x_ast\tError p_ast\tline search\n"))
    cat(sprintf("%d\t%.2e\t%0.2e\t%0.2e\t%s\n",iteration,normgf,Err,Err_plot_aux[iteration],"---"))
    iteration<-iteration + 1
    while(normgf>tol && iteration < maxiter){
        ind_maximo <- which.max(abs(gfeval))
        e_canonical <- vector("integer",n)
        e_canonical[ind_maximo] <- gfeval[ind_maximo]
        dir_desc <- -e_canonical
        der_direct <- sum(gfeval*dir_desc)
        t <- line_search_by_backtracking(f,dir_desc,x,der_direct)
        x <- x + t*dir_desc
        feval <- f(x)
        if (!is.null(gf_symbolic)){
            gfeval <- gf_symbolic(x)
        }else{
            gfeval <- gradient_approximation(f,x)
        }   
        normgf <- Euclidian_norm(gfeval)
        Err_plot_aux[iteration] <- compute_error(p_ast,feval)
        x_plot[,iteration] <- x
        Err <- compute_error(x_ast,x)
        cat(sprintf("%d\t%.2e\t%0.2e\t%0.2e\t%0.2e\n",iteration,normgf,Err,Err_plot_aux[iteration],t))
        if (t<tol_backtracking){ #if t is less than tol_backtracking then we need to check the reason
            iter_salida <- iteration
            iteration <- maxiter - 1
        }
        iteration <- iteration + 1
    } #while
    cat(sprintf("Error of x with respect to x_ast: %.2e\n",Err))
    cat(sprintf("Approximate solution:"))
    print(x)
    cond <- Err_plot_aux > .Machine$double.eps*10**(-2)
    Err_plot <- Err_plot_aux[cond]
    if (iteration == maxiter && t < tol_backtracking){
        print("Backtracking value less than tol_backtracking, check approximation")
        iteration<-iter_salida
        x_plot <- x_plot[,1:iteration]
        iteration <- iteration -1
    }
    else{
        iteration <- iteration - 1
        x_plot <- x_plot[,1:iteration]
        }
   list(x,iteration,Err_plot,x_plot)
    
}
                 
Newtons_method<-function(f, x_0, tol, 
                        tol_backtracking, x_ast, p_ast, maxiter=30,
                        gf_symbolic=NULL, Hf_symbolic=NULL){
    '
    Method of gradient descent to numerically approximate solution of min f.
    Args:
        f (expression): definition of function f.
        x_0 (double): vector of initial point for gradient descent method.
        tol (float): tolerance that will halt method. Controls norm of gradient of f.
        tol_backtracking (float): tolerance that will halt method. Controls value of line search by backtracking.
        x_ast (double): vector solution of min f, now its required that user knows the solution...
        p_ast (double): vector value of f(x_ast), now its required that user knows the solution...
        maxiter (int): maximum number of iterations.
        gf_symbolic (fun): definition of gradient of f. If given, no approximation is
                                     performed via finite differences.
        Hf_symbolic (fun): definition of Hessian of f. If given, no approximation is
                                     performed via finite differences.
    Returns:
        x (double): vector approximation of x_ast.
        iteration (int): number of iterations.
        Err_plot (double): vector array of absolute error between p_ast and f(x) with x approximation.
                          of x_ast. Useful for plotting.
        x_plot (double): vector array that containts in columns vector of approximations. Last column
                        contains x, approximation of solution. Useful for plotting.
    '
    iteration <- 1
    x <- x_0
    
    feval <- f(x)
    if (!is.null(gf_symbolic)){
        gfeval <- gf_symbolic(x)
    }else{
        gfeval <- gradient_approximation(f,x)
    }

    if (!is.null(Hf_symbolic)){
        Hfeval <- Hf_symbolic(x)
    }else{
        Hfeval <- Hessian_approximation(f,x)
    }
    
    condHf <- kappa(Hfeval, exact=TRUE)
    
    normgf <- Euclidian_norm(gfeval)
    
    Err_plot_aux <- vector("double",maxiter)
    Err_plot_aux[iteration] <- compute_error(p_ast,feval)
    
    Err <- compute_error(x_ast,x)
    n <- length(x)
    x_plot <- matrix(0,nrow=n,ncol=maxiter)
    x_plot[,iteration] <- x
    
    #Newton's direction and Newton's decrement
    
    dir_Newton <- solve(Hfeval, -gfeval)
    dec_Newton <- -sum(gfeval*dir_Newton)
    
    cat(sprintf("I\tNormgf\tNewton Decrement\tError x_ast\tError p_ast\tline search\tcondHf\n"))
    cat(sprintf("%d\t%.2e\t%0.2e\t%0.2e\t%0.2e\t%s\t\t%0.2e\n",iteration,normgf,dec_Newton,
                                                             Err,Err_plot_aux[iteration],"---", condHf))
    
    stopping_criteria <- dec_Newton/2
    iteration<-iteration + 1
    while(stopping_criteria>tol && iteration < maxiter){
        der_direct <- -dec_Newton
        t <- line_search_by_backtracking(f,dir_Newton,x,der_direct)
        x <- x + t*dir_Newton
        feval <- f(x)
        if (!is.null(gf_symbolic)){
            gfeval <- gf_symbolic(x)
        }else{
            gfeval <- gradient_approximation(f,x)
        } 
        if (!is.null(Hf_symbolic)){
            Hfeval <- Hf_symbolic(x)
        }else{
            Hfeval <- Hessian_approximation(f,x)
        }
        normgf <- Euclidian_norm(gfeval)
        condHf <- kappa(Hfeval, exact=TRUE)
        #Newton's direction and Newton's decrement
            
        dir_Newton <- solve(Hfeval, -gfeval)
        dec_Newton <- -sum(gfeval*dir_Newton)
        Err_plot_aux[iteration] <- compute_error(p_ast,feval)
        x_plot[,iteration] <- x
        Err <- compute_error(x_ast,x)
        cat(sprintf("%d\t%.2e\t%0.2e\t%0.2e\t%0.2e\t%0.2e\t%0.2e\n",iteration,normgf,dec_Newton,
                                                                    Err,Err_plot_aux[iteration],t, condHf))
        stopping_criteria <- dec_Newton/2
        if (t<tol_backtracking){ #if t is less than tol_backtracking then we need to check the reason
            iter_salida <- iteration
            iteration <- maxiter - 1
        }
        iteration <- iteration + 1
    } #while
    cat(sprintf("Error of x with respect to x_ast: %.2e\n",Err))
    cat(sprintf("Approximate solution:"))
    print(x)
    cond <- Err_plot_aux > .Machine$double.eps*10**(-2)
    Err_plot <- Err_plot_aux[cond]
    if (iteration == maxiter && t < tol_backtracking){
        print("Backtracking value less than tol_backtracking, check approximation")
        iteration<-iter_salida
        x_plot <- x_plot[,1:iteration]
        iteration <- iteration -1
    }
    else{
        iteration <- iteration - 1
        x_plot <- x_plot[,1:iteration]
        }
   list(x,iteration,Err_plot,x_plot)
    
}    

