/*ckwg +29
 * Copyright 2011-2012 by Kitware, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sprokit/pipeline_util/export_dot.h>
#include <sprokit/pipeline_util/export_dot_exception.h>

#include <sprokit/python/util/pystream.h>
#include <sprokit/python/util/python_gil.h>

#include <boost/python/def.hpp>
#include <boost/python/module.hpp>
#include <boost/python/exception_translator.hpp>

#include <boost/python.hpp>

#include <string>

/**
 * \file export.cxx
 *
 * \brief Python bindings for exporting functions.
 */

using namespace boost::python;

void export_dot(object const& stream, sprokit::pipeline_t const pipe, std::string const& graph_name);

BOOST_PYTHON_MODULE(export_)
{
  def("export_dot", &export_dot
    , (arg("stream"), arg("pipeline"), arg("name"))
    , "Writes the pipeline to the stream in dot format.");
}

void
export_dot(object const& stream, sprokit::pipeline_t const pipe, std::string const& graph_name)
{
  sprokit::python::python_gil const gil;

  (void)gil;

  sprokit::python::pyostream ostr(stream);

  return sprokit::export_dot(ostr, pipe, graph_name);
}
