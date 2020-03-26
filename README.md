# mydemo
  A toy Python package with C extension.  

# Installation

    pip install git+https://github.com/Tesla-Xiao/mydemo.git

# Usage

   - [x] [python_calling_c-manual](https://xliusufe.gitee.io/cp/rpk.html#3_python_calling_cc++) ------------ Details of the usage of the package.
   
# Example

    import numpy as np
    import Demo

    n  = 4
    p  = 5
    X  = []
    for _ in range(n):
        X.append(np.random.normal(size= p))
    x = np.asarray(X)

    y = np.random.choice(10, p)

    Demo.mycfunc(x, y, 3.14, 2020)  // Trigger the error we set.

    y = np.random.choice(10, n)

    Demo.mycfunc(x, y, 3.14, 2020)

# Development
The Python-package is developed by Xiao Zhang (zhangxiao_0422@163.com).
