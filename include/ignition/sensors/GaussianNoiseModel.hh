/*
 * Copyright (C) 2018 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef IGNITION_SENSORS_GAUSSIANNOISEMODEL_HH_
#define IGNITION_SENSORS_GAUSSIANNOISEMODEL_HH_

#include <sdf/sdf.hh>

#include <ignition/rendering/RenderTypes.hh>
#include <ignition/sensors/Noise.hh>
#include <ignition/sensors/Export.hh>

namespace ignition
{
  // class GaussianNoiseCompositorListener;
  namespace sensors
  {
    // Forward declarations
    class GaussianNoiseModelPrivate;

    /** \class GaussianNoiseModel GaussianNoiseModel.hh \
    ignition/sensors/GaussianNoiseModel.hh
    **/
    /// \brief Gaussian noise class
    class IGNITION_SENSORS_VISIBLE GaussianNoiseModel : public Noise
    {
      /// \brief Constructor.
      public: GaussianNoiseModel();

      /// \brief Destructor.
      public: virtual ~GaussianNoiseModel();

      // Documentation inherited.
      public: virtual void Load(sdf::ElementPtr _sdf);

      // Documentation inherited.
      public: double ApplyImpl(double _in);

      /// \brief Accessor for mean.
      /// \return Mean of Gaussian noise.
      public: double Mean() const;

      /// \brief Accessor for stddev.
      /// \return Standard deviation of Gaussian noise.
      public: double StdDev() const;

      /// \brief Accessor for bias.
      /// \return Bias on output.
      public: double Bias() const;

      /// Documentation inherited
      public: virtual void Print(std::ostream &_out) const;

      /// \brief Private data pointer.
      private: GaussianNoiseModelPrivate *dataPtr = nullptr;
    };

    /// \class GaussianNoiseModel
    /// \brief Gaussian noise class for image sensors
    class IGNITION_SENSORS_VISIBLE ImageGaussianNoiseModel :
      public GaussianNoiseModel
    {
      /// \brief Constructor.
      public: ImageGaussianNoiseModel();

      /// \brief Destructor.
      public: virtual ~ImageGaussianNoiseModel();

      // Documentation inherited.
      public: virtual void Load(sdf::ElementPtr _sdf);

      // Documentation inherited.
      public: virtual void Fini();

      // Documentation inherited.
      public: virtual void SetCamera(rendering::CameraPtr _camera);

      /// Documentation inherited
      public: virtual void Print(std::ostream &_out) const;

      /*
      TODO: implement compositor instance in ign-rendering
      /// \brief Gaussian noise compositor.
      public: Ogre::CompositorInstance *gaussianNoiseInstance;


      /// \brief Gaussian noise compositor listener
      public: std::shared_ptr<GaussianNoiseCompositorListener>
        gaussianNoiseCompositorListener;
      */
    };
  }
}

#endif