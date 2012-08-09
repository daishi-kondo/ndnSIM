/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 University of California, Los Angeles
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Alexander Afanasyev <alexander.afanasyev@ucla.edu>
 */

#ifndef NDN_CONSUMER_BATCHES_H
#define NDN_CONSUMER_BATCHES_H

#include "ndn-consumer.h"
#include "ns3/traced-value.h"
#include "ns3/batches.h"

namespace ns3 
{

/**
 * @ingroup ndn
 * \brief Ndn application for sending out Interest packets in batches
 */
class NdnConsumerBatches: public NdnConsumer
{
public: 
  static TypeId GetTypeId ();
        
  /**
   * \brief Default constructor 
   */
  NdnConsumerBatches ();

  // From NdnApp
  // virtual void
  // OnInterest (const Ptr<const NdnInterestHeader> &interest);

  // virtual void
  // OnNack (const Ptr<const NdnInterestHeader> &interest);

  // virtual void
  // OnContentObject (const Ptr<const NdnContentObjectHeader> &contentObject,
  //                  const Ptr<const Packet> &payload);

  // virtual void
  // OnTimeout (uint32_t sequenceNumber);

private:
  Batches
  GetBatch () const { return Batches(); }

  void
  SetBatch (const Batches &batch);
  
  void
  AddBatch (uint32_t amount);
protected:
  /**
   * \brief Constructs the Interest packet and sends it using a callback to the underlying Ndn protocol
   */
  virtual void
  ScheduleNextPacket ();
};

} // namespace ns3

#endif