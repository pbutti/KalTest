#ifndef TSTRAIGHTTRACK_H
#define TSTRAIGHTTRACK_H
//*************************************************************************
//* ======================
//*  TStraightTrack Class
//* ======================
//*
//* (Description)
//*   A class to implement a straight track object.
//*
//*   The stragiht track is implemented as the kappa->infinity limit
//*   of a helical track:
//*
//*      x = x0 + drho * cos(phi0) - t * sin(phi0)
//*      y = y0 + drho * sin(phi0) + t * cos(phi0)
//*      z = z0 + dz               + t * tan(lambda)
//*
//* (Requires)
//*     TVTrack, TCylinder, TCircle, TVector3, TMatrixD
//* (Provides)
//*     class TStraightTrack
//* (Update Recored)
//*   2003/10/24  K.Fujii       Original version.
//*
//*************************************************************************
//

#include "TVTrack.h"

//_____________________________________________________________________
//  -----------------------------------
//  Straight Track Class
//  -----------------------------------

class TStraightTrack : public TVTrack {
public:

   // Ctors and Dtor

   TStraightTrack(Double_t dr    = 0.,
                  Double_t phi0  = 0.,
                  Double_t m     = 5., //not used
                  Double_t dz    = 0.,
                  Double_t tanl  = 0.,
                  Double_t x0    = 0.,
                  Double_t y0    = 0.,
                  Double_t z0    = 0.,
                  Double_t b     = 0.);

   TStraightTrack(const TMatrixD &a, const TVector3 & x0, Double_t b = 0.);

   virtual ~TStraightTrack() {}

   // Utility methods

   virtual void MoveTo(const TVector3 &x0to,
                             Double_t &t,
                             TMatrixD *F = 0,
                             TMatrixD *C = 0,
			     Bool_t   transform = kFALSE); //transform has no meaning for straight track

   TVector3 CalcXAt   (Double_t phi) const;
   TMatrixD CalcDxDa  (Double_t phi) const;
   TMatrixD CalcDxDphi(Double_t phi) const;
   void     CalcDapDa (Double_t fid,
                       Double_t dr,
                       Double_t drp,
                       TMatrixD &F)  const;

   inline virtual  Double_t   GetMomentum() const     { return fMomentum; }

private:

   //For straight track, we can not get the momentum from track fitting. 
   //However, a fixed value of momentum is used to calculate the multiple scattering.
   Double_t fMomentum;

   ClassDef(TStraightTrack,1)      // circle class
};

#endif

