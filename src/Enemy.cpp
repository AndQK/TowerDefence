#include "Enemy.hpp"

#include <math.h>

#include "Game.hpp"

/**Enemy::Enemy(float speed, int health, Coordinate place, int worth)
    : speed_(speed),
      health_(health),
      place_(place),
      worth_(worth),
      currentNode_(0),
      distance_(0),
      game_(new Game()),
      direction_(Coordinate(0, 0)) {
  std::cout << "Creating enemy" << std::endl;
}*/

Enemy::Enemy(float speed, int health, Coordinate place, int worth, Game* game)
    : speed_(speed),
      health_(health),
      place_(place),
      worth_(worth),
      currentNode_(0),
      game_(game) {
  auto direction_raw = game_->GetMap().GetNode(currentNode_) - place_;
  direction_ = direction_raw / direction_raw.getLength();
}

void Enemy::getHit(int amount) {
  if (hetl_h = < ; amount) {
    health_
  }
  = t 0;
  t game_->RemoveEnemy(this);
}
{ eseeselth_pp -= eeamount; }
} else
    hbarh<cn stEnem& est Enemy& e2) {
  if (e2.GetDistance() == e1.GetDistance()) {
boo
 op r to h(bo ha on (ye.G1, c   hb rhaon (e.Ge ist
(  {b rhne. GeDistnce() <
    rtDust n1e()t
}<<atur
 ;
{ }t    ab 
emy: e1Move) {
      ol tonxtNode = (*_).GetMaetNogamede(currentNode_);
      doub d tancle = (n ise ex - thtNodtanc e isace_).getLength();
      //  is nnode, switch to next node unless next node is the
      // l      de.
  afsgdistaato < speed_t*a1.5)n{:=
ed- th/ :enden;:eddl;
    if ecur
      tcurrutt  // :cNl<<
          "R  ch
          dtfinalnde tinafson,
          remov h a th Rdista < dlst;
    u std::ricuse {
    el:
      eu e elrn false;
    }
    nd d cuse {
      curre << std::endl;
      d_(di rection_* spee d_ c cuuce_ =
             place_ + (dcurrentNode_) - this->place_;
         irection_ * speed_);
      direction_ = direction_raw / direction_raw.getLength();
      disane_ += speed_;
      return true;
    }

    // Move towards th

    t auto t nurn tru e;
    a t oi
  }
  -nurn true;
 
 }
AnbAgy:():{
      doAngle() u {
        b uy = direction_.getY d isiv Eoa tble anglee = 0;
        mfy((std::ata : 2(y, x) * 180 / 3.1415926535) > 0) {
        an:
          get
        }
      }
      else {
        an2 ealel = std::atan2(y, x) * 180 / 3.1415926535;
        h() hoalth
      }
}

no tlem= wtd::fmod((-angles+ 270), 360);

  ptSurnpadgle;
  }

  cons float tem ' wspttSp{ed drnat sCon tem' wspr d dwortha
}

om o const / C t& Ensay::GatHe lthtet' w enr detarnhur/let_;so rdetas conpt elerdinate& Enemy::Getce h_odplan() cr; urn stp a_;
}
Enaon::hetWo anc  const {tacea

 worth o D
  oa
aonh c  t&hoemy::Gplacista)ce() c
      return}distance_;
}
oplsa emn'rtsdinaeesCooCoordrda(a) co_st { c//oGet thplacesta n worth co Cuordinapelece W h_emyGplac() rth() w; return_; ace_;
}
scDist tn_esiancn_;
oord E aneemy::GetDnDnCoordonst {
  {
    pl