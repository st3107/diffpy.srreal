/*****************************************************************************
*
* diffpy.srreal     by DANSE Diffraction group
*                   Simon J. L. Billinge
*                   (c) 2009 Trustees of the Columbia University
*                   in the City of New York.  All rights reserved.
*
* File coded by:    Pavol Juhas
*
* See AUTHORS.txt for a list of people who contributed.
* See LICENSE.txt for license information.
*
******************************************************************************
*
* class PeakProfile -- base class for calculation of peak profiles.
*     When possible total integrated area of the profile should eqaul 1.
*     The method y(x, fwhm) returns amplitude of a zero-centered profile.
*     Methods xboundlo(fwhm), xboundhi(fwhm) return low and high x-boundaries,
*     where amplitude relative to the maximum becomes smaller than precision
*     set by setPrecision().
*
* $Id$
*
*****************************************************************************/

#ifndef PEAKPROFILE_HPP_INCLUDED
#define PEAKPROFILE_HPP_INCLUDED

#include <string>
#include <map>

namespace diffpy {
namespace srreal {

class PeakProfile
{
    public:

        // constructors
        virtual PeakProfile* create() const = 0;
        virtual PeakProfile* copy() const = 0;
        PeakProfile() : mprecision(0.0)  { }
        virtual ~PeakProfile()  { }

        // methods
        virtual const std::string& type() const = 0;
        virtual double y(double x, double fwhm) const = 0;
        virtual double xboundlo(double fwhm) const = 0;
        virtual double xboundhi(double fwhm) const = 0;
        virtual void setPrecision(double eps);
        virtual double getPrecision() const;

    private:

        // data
        double mprecision;
};

// Factory functions for Peak Width Models -----------------------------------

PeakProfile* createPeakProfile(const std::string& tp);
bool registerPeakProfile(const PeakProfile&);
bool aliasPeakProfile(const std::string& tp, const std::string& al);

}   // namespace srreal
}   // namespace diffpy

#endif  // PEAKPROFILE_HPP_INCLUDED
