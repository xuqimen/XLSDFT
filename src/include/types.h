#ifndef _TYPES_H_
#define _TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


typedef
struct _Atom {
    char tag[16];  //
    int zion;      // 
    int zval;
    double atom_reds[3];
    double atom_carts[3];
} Atom;



typedef
struct _Geometry {
    double a1[3]; // lattice vector
    double a2[3]; // lattice vector
    double a3[3]; // lattice vector
    double volume;
    int BCs[3]; // boundary conditions
    int natom;
    Atom *atoms;
} Geometry;
 

typedef
struct _BrillouinZone {
    int kpt_grid[3];
    double kpt_shift[3];
    double b1[3]; // reciprocal lattice vector
    double b2[3]; // reciprocal lattice vector
    double b3[3]; // reciprocal lattice vector
    double volume_BZ;
    // symmetry-reduced kpoints
    int nkpt_symm;
    double *kpt_symm_reds;
    double *kpt_symm_carts;
    double *kpt_symm_weights;
} BrillouinZone;


typedef
struct _Discretization {
    int fd_order;
    int fd_grid[3];
    double meshes[3];
    double *fd_coeffs;
    double *fd_weights; // includes mesh info
} Discretization;


typedef
struct _Control {
    int maxit_scf;
    double tol_scf;
    int maxit_poisson;
    double tol_poisson;
} Control;


typedef
struct _Paral {
    // density matrix solver cartesian topology dims
    int npspin;
    int npkpt;
    int npdomain;
    int domain_cartdims[3];
    // poisson solver cartesian topology dims
    int nppoisson;
    int poisson_cartdims[3];
} Paral;



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // _TYPES_H_
