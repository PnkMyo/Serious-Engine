/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"

#include "Entities/StdH/StdH.h"

#include <Entities/GhostBusterRay.h>
#include <Entities/GhostBusterRay_tables.h>
CEntityEvent *EGhostBusterRay::MakeCopy(void) { CEntityEvent *peeCopy = new EGhostBusterRay(*this); return peeCopy;}
EGhostBusterRay::EGhostBusterRay() : CEntityEvent(EVENTCODE_EGhostBusterRay) {;
 ClearToDefault(penOwner);
};
#line 16 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"

#define HIT_DISTANCE 50.0f      // ray hit distance
#define HIT_DAMAGE 15.0f         // hit damage for every lerping bullet

void CGhostBusterRay_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) 
{
  pdec->PrecacheClass(CLASS_BULLET);
  pdec->PrecacheModel(MODEL_RAY);
  pdec->PrecacheTexture(TEXTURE_RAY);
}

void CGhostBusterRay::SetDefaultProperties(void) {
  m_penOwner = NULL;
  m_bRender = FALSE ;
  m_vSrcOld = FLOAT3D(0.0f , 0.0f , 0.0f);
  m_vDstOld = FLOAT3D(0.0f , 0.0f , 0.0f);
  m_vSrc = FLOAT3D(0.0f , 0.0f , 0.0f);
  m_vDst = FLOAT3D(0.0f , 0.0f , 0.0f);
  m_iLastBulletPosition = FLOAT3D(32000.0f , 32000.0f , 32000.0f);
  m_aoLightAnim.SetData(NULL);

  m_ctPasses = 0;
  m_penPrediction = NULL;
  CMovableModelEntity::SetDefaultProperties();
}
  
#line 61 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
void CGhostBusterRay::AddDependentsToPrediction(void) 
#line 62 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
{
#line 63 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
m_penOwner  -> AddToPrediction  ();
#line 64 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}
  
#line 66 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
void CGhostBusterRay::RenderParticles(void) 
#line 67 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
{
#line 68 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
if(m_ctPasses  < 2){
#line 69 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
return ;
#line 70 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}
#line 71 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
FLOAT3D vLerpedSrc  = Lerp  (m_vSrcOld  , m_vSrc  , _pTimer  -> GetLerpFactor  ());
#line 72 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
FLOAT3D vLerpedDst  = Lerp  (m_vDstOld  , m_vDst  , _pTimer  -> GetLerpFactor  ());
#line 73 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
Particles_Ghostbuster  (vLerpedSrc  , vLerpedDst  , 32 , 1.0f);
#line 74 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}
  
#line 77 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
void CGhostBusterRay::Read_t(CTStream * istr) 
#line 78 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
{
#line 79 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
CMovableModelEntity  :: Read_t  (istr );
#line 80 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
SetupLightSource  ();
#line 81 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}
  
#line 84 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
CLightSource * CGhostBusterRay::GetLightSource(void) 
#line 85 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
{
#line 86 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
if(! IsPredictor  ()){
#line 87 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
return & m_lsLightSource ;
#line 88 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}else {
#line 89 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
return NULL ;
#line 90 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}
#line 91 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}
  
#line 94 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
void CGhostBusterRay::SetupLightSource(void) 
#line 95 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
{
#line 97 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
CLightSource  lsNew ;
#line 98 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
lsNew  . ls_ulFlags  = LSF_NONPERSISTENT  | LSF_DYNAMIC ;
#line 99 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
lsNew  . ls_colColor  = RGBToColor  (134 , 238 , 255);
#line 100 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
lsNew  . ls_rFallOff  = 10.0f;
#line 101 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
lsNew  . ls_rHotSpot  = 1.0f;
#line 102 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
lsNew  . ls_plftLensFlare  = NULL ;
#line 103 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
lsNew  . ls_ubPolygonalMask  = 0;
#line 104 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
lsNew  . ls_paoLightAnimation  = & m_aoLightAnim ;
#line 106 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
m_lsLightSource  . ls_penEntity  = this ;
#line 107 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
m_lsLightSource  . SetLightSource  (lsNew );
#line 108 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}
  
#line 115 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
void CGhostBusterRay::DoMoving(void) {
#line 116 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
en_plLastPlacement  = GetPlacement  ();
#line 117 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}
  
#line 119 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
void CGhostBusterRay::PostMoving(void) {
#line 120 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
if(! IsOfClass  (m_penOwner  , "Player Weapons")){return ;}
#line 123 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
CPlacement3D plSource ;
#line 124 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
((CPlayerWeapons  &) * m_penOwner ) . GetGhostBusterSourcePlacement  (plSource );
#line 125 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
FLOAT3D vDirection  , vDesired ;
#line 126 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
AnglesToDirectionVector  (plSource  . pl_OrientationAngle  , vDirection );
#line 127 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
vDesired  = vDirection  * HIT_DISTANCE ;
#line 128 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
vDesired  = plSource  . pl_PositionVector  + vDesired ;
#line 131 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
CCastRay  crRay  (((CPlayerWeapons  &) * m_penOwner ) . m_penPlayer  , plSource  . pl_PositionVector  , vDesired );
#line 132 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
m_vSrcOld  = m_vSrc ;
#line 133 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
m_vSrc  = plSource  . pl_PositionVector ;
#line 134 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
crRay  . cr_bHitTranslucentPortals  = FALSE ;
#line 135 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
crRay  . cr_ttHitModels  = CCastRay  :: TT_COLLISIONBOX ;
#line 136 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
GetWorld  () -> CastRay  (crRay );
#line 139 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
if(crRay  . cr_penHit  != NULL ){
#line 140 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
vDesired  = crRay  . cr_vHit ;
#line 141 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}
#line 142 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
vDesired  -= vDirection  / 10.0f;
#line 144 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
m_vDstOld  = m_vDst ;
#line 145 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
m_vDst  = vDesired ;
#line 148 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
FLOAT fStretch  = (plSource  . pl_PositionVector  - vDesired ) . Length  ();
#line 150 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
GetModelObject  () -> mo_Stretch  (3) = 0.001f;
#line 152 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
CPlacement3D plSet ;
#line 153 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
plSet  . pl_PositionVector  = vDesired ;
#line 154 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
plSet  . pl_OrientationAngle  = plSource  . pl_OrientationAngle ;
#line 155 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
SetPlacement  (plSet );
#line 156 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
m_ctPasses  ++;
#line 157 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}
  
#line 165 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
void CGhostBusterRay::PrepareBullet(const CPlacement3D & plBullet) {
#line 167 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
penBullet  = CreateEntity  (plBullet  , CLASS_BULLET );
#line 169 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
EBulletInit  eInit ;
#line 170 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
eInit  . penOwner  = ((CPlayerWeapons  &) * m_penOwner ) . m_penPlayer ;
#line 171 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
eInit  . fDamage  = HIT_DAMAGE ;
#line 172 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
penBullet  -> Initialize  (eInit );
#line 173 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
((CBullet  &) * penBullet ) . m_EdtDamage  = DMT_BULLET ;
#line 174 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}
  
#line 177 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
void CGhostBusterRay::Fire(const CPlacement3D & plSource) {
#line 178 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
if(! IsOfClass  (m_penOwner  , "Player Weapons")){return ;}
#line 181 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
PrepareBullet  (plSource );
#line 182 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
((CBullet  &) * penBullet ) . CalcTarget  (HIT_DISTANCE );
#line 183 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
((CBullet  &) * penBullet ) . m_fBulletSize  = 0.5f;
#line 184 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
((CBullet  &) * penBullet ) . CalcJitterTarget  (0.02f * HIT_DISTANCE );
#line 185 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
((CBullet  &) * penBullet ) . LaunchBullet  (TRUE  , FALSE  , TRUE );
#line 186 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
((CBullet  &) * penBullet ) . DestroyBullet  ();
#line 187 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}
  
#line 190 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
void CGhostBusterRay::DestroyGhostBusterRay(void) {
#line 191 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
Destroy  ();
#line 192 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}
BOOL CGhostBusterRay::
#line 201 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CGhostBusterRay_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EGhostBusterRay, "CGhostBusterRay::Main expects 'EGhostBusterRay' as input!");  const EGhostBusterRay &egbr = (const EGhostBusterRay &)__eeInput;
#line 203 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
ASSERT  (egbr  . penOwner  != NULL );
#line 204 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
m_penOwner  = egbr  . penOwner ;
#line 207 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
InitAsModel  ();
#line 208 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 209 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 210 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
SetModel  (MODEL_RAY );
#line 211 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
SetModelMainTexture  (TEXTURE_RAY );
#line 213 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
try {
#line 214 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
m_aoLightAnim  . SetData_t  (CTFILENAME  ("Animations\\GhostbusterLightning.ani"));
#line 215 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
m_aoLightAnim  . PlayAnim  (0 , AOF_LOOPING );
#line 216 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}catch  (char  * strError ){
#line 217 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
CPrintF  ("%s" , strError );
#line 218 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
}
#line 221 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
SetupLightSource  ();
#line 224 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
AddToMovers  ();
#line 225 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
m_ctPasses  = 0;
#line 227 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
Return(STATE_CURRENT,EVoid());
#line 227 "/home/seb/git/Serious-Seb/Sources/Entities/GhostBusterRay.es"
return TRUE; ASSERT(FALSE); return TRUE;};