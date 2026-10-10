/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40925dc0 FUN_40925dc0 */

/* Boundary evidence: original MIPS .pdata 40925dc0..40925efb. Semantic name remains unreviewed. */

int FUN_40925dc0(HMODULE param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40938b24 != (code *)0x0) {
      iVar2 = (*DAT_40938b24)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40925e70;
    FUN_4092612c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40931d1c(param_1,param_2,param_3,param_4);
  }
LAB_40925e70:
  if (((param_2 == 0) && (FUN_409260b4(), iVar1 != 0)) && (DAT_40938b24 != (code *)0x0)) {
    iVar1 = (*DAT_40938b24)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40925efc FUN_40925efc */

/* Boundary evidence: original MIPS .pdata 40925efc..40925f27. Semantic name remains unreviewed. */

void FUN_40925efc(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40925f28 entry */

/* Boundary evidence: original MIPS .pdata 40925f28..40925f7f. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_2 == 1) {
    FUN_40926168();
  }
  FUN_40925dc0(param_1,param_2,param_3,param_4);
  return;
}



/* 40925f80 FUN_40925f80 */

/* Boundary evidence: original MIPS .pdata 40925f80..40925fc7. Semantic name remains unreviewed. */

void FUN_40925f80(uint param_1)

{
  if ((param_1 == DAT_4093827c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40925fc8 FUN_40925fc8 */

/* Boundary evidence: original MIPS .pdata 40925fc8..409260b3. Semantic name remains unreviewed. */

void FUN_40925fc8(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_40938ae0 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40938b20;
    if (DAT_40938b20 != (undefined4 *)0x0) {
      while (DAT_40938b1c = DAT_40938b1c + -1, _Memory <= DAT_40938b1c) {
        if ((code *)*DAT_40938b1c != (code *)0x0) {
          (*(code *)*DAT_40938b1c)();
          _Memory = DAT_40938b20;
        }
      }
      free(_Memory);
      DAT_40938b1c = (undefined4 *)0x0;
      DAT_40938b20 = (undefined4 *)0x0;
    }
    FUN_409260d8((undefined4 *)&DAT_40921010,(undefined4 *)&DAT_40921014);
  }
  FUN_409260d8((undefined4 *)&DAT_40921018,(undefined4 *)&DAT_4092101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 409260b4 FUN_409260b4 */

/* Boundary evidence: original MIPS .pdata 409260b4..409260d7. Semantic name remains unreviewed. */

void FUN_409260b4(void)

{
  FUN_40925fc8(0,0,1);
  return;
}



/* 409260d8 FUN_409260d8 */

/* Boundary evidence: original MIPS .pdata 409260d8..4092612b. Semantic name remains unreviewed. */

void FUN_409260d8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 4092612c FUN_4092612c */

/* Boundary evidence: original MIPS .pdata 4092612c..40926167. Semantic name remains unreviewed. */

void FUN_4092612c(void)

{
  FUN_409260d8((undefined4 *)&DAT_40921008,(undefined4 *)&DAT_4092100c);
  FUN_409260d8((undefined4 *)&DAT_40921000,(undefined4 *)&DAT_40921004);
  return;
}



/* 40926168 FUN_40926168 */

/* Boundary evidence: original MIPS .pdata 40926168..409261db. Semantic name remains unreviewed. */

void FUN_40926168(void)

{
  uint uVar1;
  
  if ((DAT_4093827c == 0) || (DAT_4093827c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_4093827c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_4093827c == 0) {
      DAT_4093827c = 0xb064;
    }
  }
  DAT_40938280 = ~DAT_4093827c;
  return;
}



/* 4092626c FUN_4092626c */

/* Boundary evidence: original MIPS .pdata 4092626c..409262ef. Semantic name remains unreviewed. */

void FUN_4092626c(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((HMODULE)*param_1 != (HMODULE)0x0) {
      FreeLibrary((HMODULE)*param_1);
      *param_1 = 0;
    }
    if ((HMODULE)param_1[1] != (HMODULE)0x0) {
      FreeLibrary((HMODULE)param_1[1]);
      param_1[1] = 0;
    }
    if ((HMODULE)param_1[2] != (HMODULE)0x0) {
      FreeLibrary((HMODULE)param_1[2]);
      param_1[2] = 0;
    }
  }
  return;
}



/* 409262f0 FUN_409262f0 */

/* Boundary evidence: original MIPS .pdata 409262f0..409269e3. Semantic name remains unreviewed. */

void FUN_409262f0(int param_1,int param_2)

{
  int iVar1;
  DWORD DVar2;
  FILE *_File;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  
  FUN_40935a10();
  if (param_2 == 1) {
    uVar5 = *(undefined4 *)(param_1 + 4);
  }
  else {
    if (param_2 != 2) goto LAB_409269d8;
    uVar5 = *(undefined4 *)(param_1 + 8);
  }
  iVar1 = GetProcAddressW(uVar5,L"_gles_initialize");
  iVar4 = (param_2 + -1) * 0x4c + param_1;
  *(int *)(iVar4 + 0x18) = iVar1;
  if (iVar1 == 0) {
    DVar2 = GetLastError();
    _File = (FILE *)getstdfilex(2);
    pcVar3 = "_gles_initialize";
  }
  else {
    iVar1 = GetProcAddressW(uVar5,L"_gles_shutdown");
    *(int *)(iVar4 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      DVar2 = GetLastError();
      _File = (FILE *)getstdfilex(2);
      pcVar3 = "_gles_shutdown";
    }
    else {
      iVar1 = GetProcAddressW(uVar5,L"_gles_make_current");
      *(int *)(iVar4 + 0x20) = iVar1;
      if (iVar1 == 0) {
        DVar2 = GetLastError();
        _File = (FILE *)getstdfilex(2);
        pcVar3 = "_gles_make_current";
      }
      else {
        iVar1 = GetProcAddressW(uVar5,L"_gles_finish");
        *(int *)(iVar4 + 0x24) = iVar1;
        if (iVar1 == 0) {
          DVar2 = GetLastError();
          _File = (FILE *)getstdfilex(2);
          pcVar3 = "_gles_finish";
        }
        else {
          iVar1 = GetProcAddressW(uVar5,L"_gles_flush");
          *(int *)(iVar4 + 0x28) = iVar1;
          if (iVar1 == 0) {
            DVar2 = GetLastError();
            _File = (FILE *)getstdfilex(2);
            pcVar3 = "_gles_flush";
          }
          else {
            iVar1 = GetProcAddressW(uVar5,L"_gles_set_draw_frame_builder");
            *(int *)(iVar4 + 0x2c) = iVar1;
            if (iVar1 == 0) {
              DVar2 = GetLastError();
              _File = (FILE *)getstdfilex(2);
              pcVar3 = "_gles_set_draw_frame_builder";
            }
            else {
              iVar1 = GetProcAddressW(uVar5,L"_gles_set_read_frame_builder");
              *(int *)(iVar4 + 0x30) = iVar1;
              if (iVar1 == 0) {
                DVar2 = GetLastError();
                _File = (FILE *)getstdfilex(2);
                pcVar3 = "_gles_set_read_frame_builder";
              }
              else {
                iVar1 = GetProcAddressW(uVar5,L"glViewport");
                *(int *)(iVar4 + 0x34) = iVar1;
                if (iVar1 == 0) {
                  DVar2 = GetLastError();
                  _File = (FILE *)getstdfilex(2);
                  pcVar3 = "glViewport";
                }
                else {
                  iVar1 = GetProcAddressW(uVar5,L"glScissor");
                  *(int *)(iVar4 + 0x38) = iVar1;
                  if (iVar1 == 0) {
                    DVar2 = GetLastError();
                    _File = (FILE *)getstdfilex(2);
                    pcVar3 = "glScissor";
                  }
                  else {
                    iVar1 = GetProcAddressW(uVar5,L"glCopyTexImage2D");
                    *(int *)(iVar4 + 0x40) = iVar1;
                    if (iVar1 == 0) {
                      DVar2 = GetLastError();
                      _File = (FILE *)getstdfilex(2);
                      pcVar3 = "glCopyTexImage2D";
                    }
                    else {
                      iVar1 = GetProcAddressW(uVar5,L"glGetError");
                      *(int *)(iVar4 + 0x3c) = iVar1;
                      if (iVar1 == 0) {
                        DVar2 = GetLastError();
                        _File = (FILE *)getstdfilex(2);
                        pcVar3 = "glGetError";
                      }
                      else {
                        iVar1 = GetProcAddressW(uVar5,L"glEGLImageTargetTexture2DOES");
                        *(int *)(iVar4 + 0x58) = iVar1;
                        if (iVar1 == 0) {
                          DVar2 = GetLastError();
                          _File = (FILE *)getstdfilex(2);
                          pcVar3 = "glEGLImageTargetTexture2DOES";
                        }
                        else if (param_2 == 1) {
                          iVar1 = GetProcAddressW(uVar5,L"_gles1_create_context");
                          *(int *)(iVar4 + 0x10) = iVar1;
                          if (iVar1 == 0) {
                            DVar2 = GetLastError();
                            _File = (FILE *)getstdfilex(2);
                            pcVar3 = "_gles1_create_context";
                          }
                          else {
                            iVar1 = GetProcAddressW(uVar5,L"_gles1_delete_context");
                            *(int *)(iVar4 + 0x14) = iVar1;
                            if (iVar1 == 0) {
                              DVar2 = GetLastError();
                              _File = (FILE *)getstdfilex(2);
                              pcVar3 = "_gles1_delete_context";
                            }
                            else {
                              iVar1 = GetProcAddressW(uVar5,L"_gles1_get_proc_address");
                              *(int *)(iVar4 + 0x4c) = iVar1;
                              if (iVar1 == 0) {
                                DVar2 = GetLastError();
                                _File = (FILE *)getstdfilex(2);
                                pcVar3 = "_gles1_get_proc_address";
                              }
                              else {
                                iVar1 = GetProcAddressW(uVar5,L"_gles1_bind_tex_image");
                                *(int *)(iVar4 + 0x44) = iVar1;
                                if (iVar1 == 0) {
                                  DVar2 = GetLastError();
                                  _File = (FILE *)getstdfilex(2);
                                  pcVar3 = "_gles1_bind_tex_image";
                                }
                                else {
                                  iVar1 = GetProcAddressW(uVar5,L"_gles1_unbind_tex_image");
                                  *(int *)(iVar4 + 0x48) = iVar1;
                                  if (iVar1 == 0) {
                                    DVar2 = GetLastError();
                                    _File = (FILE *)getstdfilex(2);
                                    pcVar3 = "_gles1_unbind_tex_image";
                                  }
                                  else {
                                    iVar1 = GetProcAddressW(uVar5,
                                                  L"_gles_setup_egl_image_from_texture");
                                    *(int *)(iVar4 + 0x50) = iVar1;
                                    if (iVar1 != 0) goto LAB_409269d8;
LAB_409267e0:
                                    DVar2 = GetLastError();
                                    _File = (FILE *)getstdfilex(2);
                                    pcVar3 = "_gles_setup_egl_image_from_texture";
                                  }
                                }
                              }
                            }
                          }
                        }
                        else {
                          if (param_2 != 2) goto LAB_409269d8;
                          iVar1 = GetProcAddressW(uVar5,L"_gles2_bind_tex_image");
                          *(int *)(iVar4 + 0x44) = iVar1;
                          if (iVar1 == 0) {
                            DVar2 = GetLastError();
                            _File = (FILE *)getstdfilex(2);
                            pcVar3 = "_gles2_bind_tex_image";
                          }
                          else {
                            iVar1 = GetProcAddressW(uVar5,L"_gles2_unbind_tex_image");
                            *(int *)(iVar4 + 0x48) = iVar1;
                            if (iVar1 == 0) {
                              DVar2 = GetLastError();
                              _File = (FILE *)getstdfilex(2);
                              pcVar3 = "_gles2_unbind_tex_image";
                            }
                            else {
                              iVar1 = GetProcAddressW(uVar5,L"_gles2_create_context");
                              *(int *)(iVar4 + 0x10) = iVar1;
                              if (iVar1 == 0) {
                                DVar2 = GetLastError();
                                _File = (FILE *)getstdfilex(2);
                                pcVar3 = "_gles2_create_context";
                              }
                              else {
                                iVar1 = GetProcAddressW(uVar5,L"_gles2_delete_context");
                                *(int *)(iVar4 + 0x14) = iVar1;
                                if (iVar1 == 0) {
                                  DVar2 = GetLastError();
                                  _File = (FILE *)getstdfilex(2);
                                  pcVar3 = "_gles2_delete_context";
                                }
                                else {
                                  iVar1 = GetProcAddressW(uVar5,L"_gles2_get_proc_address");
                                  *(int *)(iVar4 + 0x4c) = iVar1;
                                  if (iVar1 == 0) {
                                    DVar2 = GetLastError();
                                    _File = (FILE *)getstdfilex(2);
                                    pcVar3 = "_gles2_get_proc_address";
                                  }
                                  else {
                                    iVar1 = GetProcAddressW(uVar5,
                                                  L"_gles_setup_egl_image_from_texture");
                                    *(int *)(iVar4 + 0x50) = iVar1;
                                    if (iVar1 == 0) goto LAB_409267e0;
                                    iVar1 = GetProcAddressW(uVar5,
                                                  L"_gles_setup_egl_image_from_renderbuffer");
                                    *(int *)(iVar4 + 0x54) = iVar1;
                                    if (iVar1 != 0) goto LAB_409269d8;
                                    DVar2 = GetLastError();
                                    _File = (FILE *)getstdfilex(2);
                                    pcVar3 = "_gles_setup_egl_image_from_renderbuffer";
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  fprintf(_File,"Failed to resolve address for %s (error 0x%x)\n",pcVar3,DVar2);
LAB_409269d8:
                    /* WARNING: Subroutine does not return */
  FUN_40935a40(0x10);
}



/* 409269e4 FUN_409269e4 */

/* Boundary evidence: original MIPS .pdata 409269e4..40927047. Semantic name remains unreviewed. */

undefined4 FUN_409269e4(undefined4 *param_1)

{
  int iVar1;
  DWORD DVar2;
  FILE *_File;
  char *pcVar3;
  
  iVar1 = GetProcAddressW(*param_1,L"_vg_is_valid_image_handle");
  param_1[0x2a] = iVar1;
  if (iVar1 == 0) {
    DVar2 = GetLastError();
    _File = (FILE *)getstdfilex(2);
    pcVar3 = "_vg_is_valid_image_handle";
  }
  else {
    iVar1 = GetProcAddressW(*param_1,L"_vg_get_parent");
    param_1[0x2b] = iVar1;
    if (iVar1 == 0) {
      DVar2 = GetLastError();
      _File = (FILE *)getstdfilex(2);
      pcVar3 = "_vg_get_parent";
    }
    else {
      iVar1 = GetProcAddressW(*param_1,L"_vg_image_lock");
      param_1[0x2c] = iVar1;
      if (iVar1 == 0) {
        DVar2 = GetLastError();
        _File = (FILE *)getstdfilex(2);
        pcVar3 = "_vg_image_lock";
      }
      else {
        iVar1 = GetProcAddressW(*param_1,L"_vg_image_unlock");
        param_1[0x2d] = iVar1;
        if (iVar1 == 0) {
          DVar2 = GetLastError();
          _File = (FILE *)getstdfilex(2);
          pcVar3 = "_vg_image_unlock";
        }
        else {
          iVar1 = GetProcAddressW(*param_1,L"_vg_lock_image_ptrset");
          param_1[0x2e] = iVar1;
          if (iVar1 == 0) {
            DVar2 = GetLastError();
            _File = (FILE *)getstdfilex(2);
            pcVar3 = "_vg_lock_image_ptrset";
          }
          else {
            iVar1 = GetProcAddressW(*param_1,L"_vg_unlock_image_ptrset");
            param_1[0x2f] = iVar1;
            if (iVar1 == 0) {
              DVar2 = GetLastError();
              _File = (FILE *)getstdfilex(2);
              pcVar3 = "_vg_unlock_image_ptrset";
            }
            else {
              iVar1 = GetProcAddressW(*param_1,L"_vg_image_ref");
              param_1[0x30] = iVar1;
              if (iVar1 == 0) {
                DVar2 = GetLastError();
                _File = (FILE *)getstdfilex(2);
                pcVar3 = "_vg_image_ref";
              }
              else {
                iVar1 = GetProcAddressW(*param_1,L"_vg_image_deref");
                param_1[0x31] = iVar1;
                if (iVar1 == 0) {
                  DVar2 = GetLastError();
                  _File = (FILE *)getstdfilex(2);
                  pcVar3 = "_vg_image_deref";
                }
                else {
                  iVar1 = GetProcAddressW(*param_1,L"_vg_image_pbuffer_to_clientbuffer");
                  param_1[0x32] = iVar1;
                  if (iVar1 == 0) {
                    DVar2 = GetLastError();
                    _File = (FILE *)getstdfilex(2);
                    pcVar3 = "_vg_image_pbuffer_to_clientbuffer";
                  }
                  else {
                    iVar1 = GetProcAddressW(*param_1,L"_vg_image_match_egl_config");
                    param_1[0x33] = iVar1;
                    if (iVar1 == 0) {
                      DVar2 = GetLastError();
                      _File = (FILE *)getstdfilex(2);
                      pcVar3 = "_vg_image_match_egl_config";
                    }
                    else {
                      iVar1 = GetProcAddressW(*param_1,L"_vg_create_global_context");
                      param_1[0x34] = iVar1;
                      if (iVar1 == 0) {
                        DVar2 = GetLastError();
                        _File = (FILE *)getstdfilex(2);
                        pcVar3 = "_vg_create_global_context";
                      }
                      else {
                        iVar1 = GetProcAddressW(*param_1,L"_vg_destroy_global_context");
                        param_1[0x35] = iVar1;
                        if (iVar1 == 0) {
                          DVar2 = GetLastError();
                          _File = (FILE *)getstdfilex(2);
                          pcVar3 = "_vg_destroy_global_context";
                        }
                        else {
                          iVar1 = GetProcAddressW(*param_1,L"_vg_create_context");
                          param_1[0x36] = iVar1;
                          if (iVar1 == 0) {
                            DVar2 = GetLastError();
                            _File = (FILE *)getstdfilex(2);
                            pcVar3 = "_vg_create_context";
                          }
                          else {
                            iVar1 = GetProcAddressW(*param_1,L"_vg_destroy_context");
                            param_1[0x37] = iVar1;
                            if (iVar1 == 0) {
                              DVar2 = GetLastError();
                              _File = (FILE *)getstdfilex(2);
                              pcVar3 = "_vg_destroy_context";
                            }
                            else {
                              iVar1 = GetProcAddressW(*param_1,L"_vg_context_resize_aquire");
                              param_1[0x38] = iVar1;
                              if (iVar1 == 0) {
                                DVar2 = GetLastError();
                                _File = (FILE *)getstdfilex(2);
                                pcVar3 = "_vg_context_resize_aquire";
                              }
                              else {
                                iVar1 = GetProcAddressW(*param_1,L"_vg_context_resize_rollback");
                                param_1[0x39] = iVar1;
                                if (iVar1 == 0) {
                                  DVar2 = GetLastError();
                                  _File = (FILE *)getstdfilex(2);
                                  pcVar3 = "_vg_context_resize_rollback";
                                }
                                else {
                                  iVar1 = GetProcAddressW(*param_1,L"_vg_context_resize_finish");
                                  param_1[0x3a] = iVar1;
                                  if (iVar1 == 0) {
                                    DVar2 = GetLastError();
                                    _File = (FILE *)getstdfilex(2);
                                    pcVar3 = "_vg_context_resize_finish";
                                  }
                                  else {
                                    iVar1 = GetProcAddressW(*param_1,L"_vg_make_current");
                                    param_1[0x3b] = iVar1;
                                    if (iVar1 == 0) {
                                      DVar2 = GetLastError();
                                      _File = (FILE *)getstdfilex(2);
                                      pcVar3 = "_vg_make_current";
                                    }
                                    else {
                                      iVar1 = GetProcAddressW(*param_1,
                                                  L"_vg_context_wait_async_rendering");
                                      param_1[0x3c] = iVar1;
                                      if (iVar1 == 0) {
                                        DVar2 = GetLastError();
                                        _File = (FILE *)getstdfilex(2);
                                        pcVar3 = "_vg_context_wait_async_rendering";
                                      }
                                      else {
                                        iVar1 = GetProcAddressW(*param_1,L"_vg_finish_hal");
                                        param_1[0x3d] = iVar1;
                                        if (iVar1 == 0) {
                                          DVar2 = GetLastError();
                                          _File = (FILE *)getstdfilex(2);
                                          pcVar3 = "_vg_finish_hal";
                                        }
                                        else {
                                          iVar1 = GetProcAddressW(*param_1,L"_vg_get_proc_address");
                                          param_1[0x3e] = iVar1;
                                          if (iVar1 == 0) {
                                            DVar2 = GetLastError();
                                            _File = (FILE *)getstdfilex(2);
                                            pcVar3 = "_vg_get_proc_address";
                                          }
                                          else {
                                            iVar1 = GetProcAddressW(*param_1,
                                                  L"_vg_set_frame_builder");
                                            param_1[0x3f] = iVar1;
                                            if (iVar1 == 0) {
                                              DVar2 = GetLastError();
                                              _File = (FILE *)getstdfilex(2);
                                              pcVar3 = "_vg_set_frame_builder";
                                            }
                                            else {
                                              iVar1 = GetProcAddressW(*param_1,
                                                  L"_vg_setup_egl_image");
                                              param_1[0x40] = iVar1;
                                              if (iVar1 != 0) {
                                                return 1;
                                              }
                                              DVar2 = GetLastError();
                                              _File = (FILE *)getstdfilex(2);
                                              pcVar3 = "_vg_setup_egl_image";
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  fprintf(_File,"Failed to resolve address for %s (error 0x%x)\n",pcVar3,DVar2);
  return 0;
}



/* 40927048 FUN_40927048 */

/* Boundary evidence: original MIPS .pdata 40927048..40927133. Semantic name remains unreviewed. */

undefined4 FUN_40927048(undefined4 *param_1)

{
  HMODULE pHVar1;
  int iVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0x43] = 0x3038;
  pHVar1 = LoadLibraryW(L"libOpenVG.dll");
  *param_1 = pHVar1;
  if (pHVar1 != (HMODULE)0x0) {
    iVar2 = FUN_409269e4(param_1);
    if (iVar2 == 0) {
      return 0;
    }
    param_1[0x43] = param_1[0x43] | 2;
  }
  pHVar1 = LoadLibraryW(L"libGLESv1_CM.dll");
  param_1[1] = pHVar1;
  if (pHVar1 != (HMODULE)0x0) {
    param_1[0x13] = 0;
    iVar2 = FUN_409262f0((int)param_1,1);
    if (iVar2 == 0) {
      return 0;
    }
    param_1[0x43] = param_1[0x43] | 1;
  }
  pHVar1 = LoadLibraryW(L"libGLESv2.dll");
  param_1[2] = pHVar1;
  if (pHVar1 != (HMODULE)0x0) {
    param_1[0x26] = 0;
    iVar2 = FUN_409262f0((int)param_1,2);
    if (iVar2 == 0) {
      return 0;
    }
    param_1[0x43] = param_1[0x43] | 4;
    return 1;
  }
  return 1;
}



/* 40927140 FUN_40927140 */

/* Boundary evidence: original MIPS .pdata 40927140..409271ab. Semantic name remains unreviewed. */

void FUN_40927140(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 200) != 0) {
    piVar1 = FUN_409319b8();
    if ((*param_2 != 0) && (iVar2 = *(int *)(*param_2 + 0xc), iVar2 != 0)) {
      (**(code **)(piVar1[0xc] + 0xc4))(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(param_1 + 200))
      ;
    }
    *(undefined4 *)(param_1 + 200) = 0;
  }
  return;
}



/* 409271ac FUN_409271ac */

/* Boundary evidence: original MIPS .pdata 409271ac..4092720f. Semantic name remains unreviewed. */

void FUN_409271ac(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  FUN_40935ae0();
  piVar1 = FUN_409319b8();
  (**(code **)(piVar1[0xc] + 200))(*(undefined4 *)(param_1 + 200),param_3);
  (**(code **)(piVar1[0xc] + 0xb4))(*(undefined4 *)(*(int *)(param_4 + 4) + 200));
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x10);
}



/* 40927210 FUN_40927210 */

/* Boundary evidence: original MIPS .pdata 40927210..40927267. Semantic name remains unreviewed. */

undefined4 FUN_40927210(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  piVar1 = FUN_409319b8();
  if (((*(uint *)(piVar1[0xc] + 0x10c) & 2) == 0) ||
     (pcVar3 = *(code **)(piVar1[0xc] + 0xf8), pcVar3 == (code *)0x0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = (*pcVar3)(param_2);
  }
  return uVar2;
}



/* 40927268 FUN_40927268 */

/* Boundary evidence: original MIPS .pdata 40927268..409272eb. Semantic name remains unreviewed. */

void FUN_40927268(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  FUN_40935b30();
  piVar1 = FUN_409319b8();
  (**(code **)(piVar1[0xc] + 0x100))(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 409272ec FUN_409272ec */

/* Boundary evidence: original MIPS .pdata 409272ec..4092731f. Semantic name remains unreviewed. */

void FUN_409272ec(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409319b8();
  (**(code **)(piVar1[0xc] + 0xf4))(*(undefined4 *)(param_1 + 0x18));
  return;
}



/* 40927320 FUN_40927320 */

/* Boundary evidence: original MIPS .pdata 40927320..40927353. Semantic name remains unreviewed. */

void FUN_40927320(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409319b8();
  (**(code **)(piVar1[0xc] + 0xf0))(*(undefined4 *)(param_1 + 0x18));
  return;
}



/* 40927354 FUN_40927354 */

/* Boundary evidence: original MIPS .pdata 40927354..409273ab. Semantic name remains unreviewed. */

bool FUN_40927354(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = FUN_409319b8();
  iVar2 = (**(code **)(piVar1[0xc] + 0xfc))
                    (*(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_1 + 8));
  return iVar2 != 0;
}



/* 409273ac FUN_409273ac */

/* Boundary evidence: original MIPS .pdata 409273ac..40927437. Semantic name remains unreviewed. */

void FUN_409273ac(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409319b8();
  if (*(int *)(param_1 + 0x18) != 0) {
    (**(code **)(piVar1[0xc] + 0xf4))();
    (**(code **)(piVar1[0xc] + 0xfc))(*(undefined4 *)(param_1 + 0x18),0);
    (**(code **)(piVar1[0xc] + 0xec))(0,0,3,0,0,0,0,0,0);
  }
  return;
}



/* 40927438 FUN_40927438 */

/* Boundary evidence: original MIPS .pdata 40927438..40927557. Semantic name remains unreviewed. */

void FUN_40927438(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  FUN_40935ae0();
  piVar1 = FUN_409319b8();
  if ((((*(int *)(param_4 + 0xc) == 0x30a1) &&
       (iVar2 = (**(code **)(piVar1[0xc] + 0xec))
                          (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_2 + 8),
                           *(undefined4 *)(param_2 + 0xc),
                           *(undefined4 *)(*(int *)(param_2 + 0xb8) + 100)), iVar2 != 0)) &&
      (*(int *)(param_2 + 200) != 0)) &&
     ((param_3 == 1 && (iVar2 = (**(code **)(piVar1[0xc] + 0xb0))(), iVar2 == 0)))) {
    (**(code **)(piVar1[0xc] + 0xec))(0,0,3,0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x28);
}



/* 40927558 FUN_40927558 */

/* Boundary evidence: original MIPS .pdata 40927558..409275cf. Semantic name remains unreviewed. */

void FUN_40927558(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409319b8();
  if (*(int *)(param_1 + 0x18) != 0) {
    (**(code **)(piVar1[0xc] + 0xf4))();
    (**(code **)(piVar1[0xc] + 0xec))(0,0,3,0,0,0,0,0,0);
  }
  return;
}



/* 409275d0 FUN_409275d0 */

/* Boundary evidence: original MIPS .pdata 409275d0..40927617. Semantic name remains unreviewed. */

undefined4 FUN_409275d0(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409319b8();
  if (*(int *)(param_1 + 0xc) != 0) {
    (**(code **)(piVar1[0xc] + 0xdc))();
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return 1;
}



/* 40927618 FUN_40927618 */

/* Boundary evidence: original MIPS .pdata 40927618..40927653. Semantic name remains unreviewed. */

void FUN_40927618(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  FUN_40935b30();
  piVar1 = FUN_409319b8();
  (**(code **)(piVar1[0xc] + 0xe8))(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 40927654 FUN_40927654 */

/* Boundary evidence: original MIPS .pdata 40927654..4092768f. Semantic name remains unreviewed. */

void FUN_40927654(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  FUN_40935b30();
  piVar1 = FUN_409319b8();
  (**(code **)(piVar1[0xc] + 0xe4))(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 40927690 FUN_40927690 */

/* Boundary evidence: original MIPS .pdata 40927690..409276cb. Semantic name remains unreviewed. */

void FUN_40927690(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  FUN_40935b30();
  piVar1 = FUN_409319b8();
  (**(code **)(piVar1[0xc] + 0xe0))(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 409276cc FUN_409276cc */

/* Boundary evidence: original MIPS .pdata 409276cc..40927813. Semantic name remains unreviewed. */

undefined4 * FUN_409276cc(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  piVar1 = FUN_409319b8();
  if (((*(uint *)(param_1 + 0x5c) & 2) == 0) || ((*(uint *)(piVar1[0xc] + 0x10c) & 2) == 0)) {
    if (param_4 == 0) {
      return (undefined4 *)0x0;
    }
    *(undefined4 *)(param_4 + 0x10) = 0x3005;
    return (undefined4 *)0x0;
  }
  puVar2 = FUN_40931f94(param_1,param_3);
  if (puVar2 == (undefined4 *)0x0) {
    if (param_4 == 0) {
      return (undefined4 *)0x0;
    }
    *(undefined4 *)(param_4 + 0x10) = 0x3003;
    return (undefined4 *)0x0;
  }
  if (param_2 != 0) {
    uVar4 = *(undefined4 *)(param_2 + 0xc);
  }
  puVar2[2] = 0x30a1;
  if (piVar1[0xd] == 0) {
    iVar3 = (**(code **)(piVar1[0xc] + 0xd0))(*(undefined4 *)(*(int *)(param_4 + 8) + 0x1c));
    piVar1[0xd] = iVar3;
    if (iVar3 == 0) goto LAB_40927790;
  }
  iVar3 = (**(code **)(piVar1[0xc] + 0xd8))
                    (*(undefined4 *)(*(int *)(param_4 + 8) + 0x1c),uVar4,piVar1[0xd]);
  puVar2[3] = iVar3;
  if (iVar3 != 0) {
    puVar2[10] = 1;
    return puVar2;
  }
LAB_40927790:
  *(undefined4 *)(param_4 + 0x10) = 0x3003;
  FUN_409320e4((int)puVar2);
  return (undefined4 *)0x0;
}



/* 40927814 FUN_40927814 */

/* Boundary evidence: original MIPS .pdata 40927814..40927c13. Semantic name remains unreviewed. */

void FUN_40927814(int param_1,int param_2,undefined4 *param_3,int *param_4)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  int *piVar8;
  int *piVar9;
  int iStack00000030;
  int iStack00000034;
  int iStack00000038;
  int iStack0000003c;
  undefined4 uStack00000040;
  undefined4 uStack00000044;
  int *in_stack_00000080;
  
  FUN_40935a70();
  uStack00000040 = 0;
  iStack00000038 = 0;
  iStack0000003c = 0;
  uStack00000044 = 0x10;
  iStack00000030 = 0;
  iStack00000034 = 0;
  piVar2 = FUN_409319b8();
  if (in_stack_00000080[3] == 0x30a0) {
    iVar4 = in_stack_00000080[1];
  }
  else {
    if (in_stack_00000080[3] != 0x30a1) goto LAB_40927c08;
    iVar4 = *in_stack_00000080;
  }
  if (iVar4 == 0) goto LAB_40927c08;
  if ((*in_stack_00000080 == 0) || (iVar4 = *(int *)(*in_stack_00000080 + 0xc), iVar4 == 0)) {
    in_stack_00000080[4] = 0x3002;
    goto LAB_40927c08;
  }
  (**(code **)(piVar2[0xc] + 0xb8))(*(undefined4 *)(iVar4 + 0xc));
  iVar4 = (**(code **)(piVar2[0xc] + 0xa8))
                    (*(undefined4 *)(*(int *)(*in_stack_00000080 + 0xc) + 0xc),param_2);
  if (iVar4 == 0) {
    iVar4 = 0x300c;
LAB_409278d4:
    in_stack_00000080[4] = iVar4;
    pcVar7 = *(code **)(piVar2[0xc] + 0xbc);
  }
  else {
    bVar1 = FUN_4092ad68(param_1,*(undefined4 *)(*(int *)(*in_stack_00000080 + 0xc) + 0xc),param_2,
                         0x30ba);
    if ((CONCAT31(extraout_var,bVar1) == 1) || (iVar4 = FUN_4092b540(param_2), iVar4 == 1)) {
      iVar4 = 0x3002;
      goto LAB_409278d4;
    }
    if ((param_3[0x17] & 2) == 0) {
      in_stack_00000080[4] = 0x3009;
      (**(code **)(piVar2[0xc] + 0xbc))(*(undefined4 *)(*(int *)(*in_stack_00000080 + 0xc) + 0xc));
      goto LAB_40927c08;
    }
    iVar4 = (**(code **)(piVar2[0xc] + 0xcc))(param_2,*param_3,param_3[1],param_3[2]);
    if (iVar4 == 0) {
      iVar4 = 0x3009;
      goto LAB_409278d4;
    }
    iVar4 = 0;
    if (param_4 != (int *)0x0) {
      iVar5 = *param_4;
      piVar3 = param_4;
      while (iVar5 != 0x3038) {
        prefetch(piVar3 + 4,0);
        iVar4 = iVar4 + 2;
        iVar5 = piVar3[2];
        piVar3 = piVar3 + 2;
      }
    }
    piVar3 = (int *)mali_sys_malloc((iVar4 + 9) * 4);
    if (piVar3 != (int *)0x0) {
      iVar4 = 0;
      iVar5 = 0;
      if (param_4 != (int *)0x0) {
        iVar6 = *param_4;
        piVar9 = piVar3;
        piVar8 = param_4;
        while (iVar6 != 0x3038) {
          iVar6 = *piVar8;
          if ((iVar6 < 0x3056) || ((0x3057 < iVar6 && ((iVar6 < 0x3087 || (0x3088 < iVar6)))))) {
            *piVar9 = iVar6;
            iVar5 = iVar5 + 2;
            piVar9[1] = piVar8[1];
            piVar9 = piVar9 + 2;
          }
          iVar4 = iVar4 + 2;
          piVar8 = param_4 + iVar4;
          iVar6 = *piVar8;
        }
      }
      piVar3[iVar5] = 0x3057;
      piVar3[iVar5 + 1] = iStack00000030;
      piVar3[iVar5 + 2] = 0x3056;
      piVar3[iVar5 + 3] = iStack00000034;
      piVar3[iVar5 + 4] = 0x3087;
      iVar4 = 0x308a;
      if (iStack00000038 != 1) {
        iVar4 = 0x3089;
      }
      piVar3[iVar5 + 5] = iVar4;
      piVar3[iVar5 + 6] = 0x3088;
      iVar4 = 0x308c;
      if (iStack0000003c != 1) {
        iVar4 = 0x308b;
      }
      piVar3[iVar5 + 7] = iVar4;
      (piVar3 + iVar5 + 7)[1] = 0x3038;
      iVar4 = FUN_4092d990(in_stack_00000080,param_1,1,(int)param_3);
      mali_sys_free(piVar3);
      if (iVar4 != 0) {
        (**(code **)(piVar2[0xc] + 0xc0))
                  (*(undefined4 *)(*(int *)(*in_stack_00000080 + 0xc) + 0xc),param_2);
        *(int *)(iVar4 + 200) = param_2;
      }
      (**(code **)(piVar2[0xc] + 0xbc))(*(undefined4 *)(*(int *)(*in_stack_00000080 + 0xc) + 0xc));
      goto LAB_40927c08;
    }
    in_stack_00000080[4] = 0x3003;
    mali_sys_free(0);
    pcVar7 = *(code **)(piVar2[0xc] + 0xbc);
  }
  (*pcVar7)(*(undefined4 *)(*(int *)(*in_stack_00000080 + 0xc) + 0xc));
LAB_40927c08:
                    /* WARNING: Subroutine does not return */
  FUN_40935aa8(0x48);
}



/* 40927c14 FUN_40927c14 */

/* Boundary evidence: original MIPS .pdata 40927c14..40927c53. Semantic name remains unreviewed. */

void FUN_40927c14(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_2 + 4) + 0xc);
  (**(code **)(*(int *)(iVar1 + 0x18) * 0x4c + *(int *)(*(int *)(param_2 + 8) + 0x30) + -4))
            (*(undefined4 *)(iVar1 + 0xc));
  return;
}



/* 40927c98 FUN_40927c98 */

/* Boundary evidence: original MIPS .pdata 40927c98..40927cf7. Semantic name remains unreviewed. */

void FUN_40927c98(int param_1)

{
  if ((*(uint *)(*(int *)(param_1 + 0x30) + 0x10c) & 1) != 0) {
    (**(code **)(*(int *)(param_1 + 0x30) + 0x1c))(param_1 + 0x38);
  }
  if ((*(uint *)(*(int *)(param_1 + 0x30) + 0x10c) & 4) != 0) {
    (**(code **)(*(int *)(param_1 + 0x30) + 0x68))(param_1 + 0x38);
  }
  return;
}



/* 40927cf8 FUN_40927cf8 */

/* Boundary evidence: original MIPS .pdata 40927cf8..40927d6b. Semantic name remains unreviewed. */

int FUN_40927cf8(int param_1)

{
  int iVar1;
  
  if ((((*(uint *)(*(int *)(param_1 + 0x30) + 0x10c) & 1) == 0) ||
      (iVar1 = (**(code **)(*(int *)(param_1 + 0x30) + 0x18))(param_1 + 0x38), iVar1 == 0)) &&
     (((*(uint *)(*(int *)(param_1 + 0x30) + 0x10c) & 4) == 0 ||
      (iVar1 = (**(code **)(*(int *)(param_1 + 0x30) + 100))(param_1 + 0x38), iVar1 == 0)))) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40927d6c FUN_40927d6c */

/* Boundary evidence: original MIPS .pdata 40927d6c..40927df3. Semantic name remains unreviewed. */

void FUN_40927d6c(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  
  piVar1 = FUN_409319b8();
  iVar2 = 0;
  if (((*(uint *)(piVar1[0xc] + 0x10c) & 1) != 0) &&
     (pcVar3 = *(code **)(piVar1[0xc] + 0x4c), pcVar3 != (code *)0x0)) {
    iVar2 = (*pcVar3)(param_2);
  }
  if ((((*(uint *)(piVar1[0xc] + 0x10c) & 4) != 0) &&
      (pcVar3 = *(code **)(piVar1[0xc] + 0x98), pcVar3 != (code *)0x0)) && (iVar2 == 0)) {
    (*pcVar3)(param_2);
  }
  return;
}



/* 40927df4 FUN_40927df4 */

/* Boundary evidence: original MIPS .pdata 40927df4..40927fb3. Semantic name remains unreviewed. */

undefined4
FUN_40927df4(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  piVar1 = FUN_409319b8();
  iVar2 = *(int *)(param_1 + 0x18);
  switch(param_2) {
  case 0x30b1:
    uVar3 = 1;
    break;
  case 0x30b3:
    uVar3 = 2;
    break;
  case 0x30b4:
    uVar3 = 3;
    break;
  case 0x30b5:
    uVar3 = 4;
    break;
  case 0x30b6:
    uVar3 = 5;
    break;
  case 0x30b7:
    uVar3 = 6;
    break;
  case 0x30b8:
    uVar3 = 7;
    break;
  case 0x30b9:
    uVar3 = 8;
  }
  if (param_2 == 0x30b9) {
    if (iVar2 == 1) {
      return 0x3000;
    }
    if (iVar2 != 2) {
      return 0x3000;
    }
    iVar2 = (**(code **)(piVar1[0xc] + 0xa0))(*(undefined4 *)(param_1 + 0xc),param_3,param_5);
  }
  else {
    iVar2 = (**(code **)(piVar1[0xc] + (iVar2 + -1) * 0x4c + 0x50))
                      (*(undefined4 *)(param_1 + 0xc),uVar3,param_3,param_4,param_5);
  }
  if (iVar2 == 1) {
    return 0x3009;
  }
  if (1 < iVar2) {
    if (iVar2 < 5) {
      return 0x300c;
    }
    if (iVar2 == 5) {
      return 0x3002;
    }
    if (iVar2 == 6) {
      return 0x3003;
    }
  }
  return 0x3000;
}



/* 40927fb4 FUN_40927fb4 */

/* Boundary evidence: original MIPS .pdata 40927fb4..40927fff. Semantic name remains unreviewed. */

void FUN_40927fb4(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409319b8();
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x18) * 0x4c + piVar1[0xc] + -0x28))
            (*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 40928000 FUN_40928000 */

/* Boundary evidence: original MIPS .pdata 40928000..4092804b. Semantic name remains unreviewed. */

void FUN_40928000(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409319b8();
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x18) * 0x4c + piVar1[0xc] + -0x24))
            (*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 4092804c FUN_4092804c */

/* Boundary evidence: original MIPS .pdata 4092804c..409281bb. Semantic name remains unreviewed. */

void FUN_4092804c(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  FUN_40935ae0();
  uVar4 = 0x1907;
  piVar1 = FUN_409319b8();
  iVar3 = *(int *)(*(int *)(*(int *)(param_2 + 4) + 0xc) + 0x18);
  if ((*(int *)(param_1 + 0xf0) != 0x305d) && (*(int *)(param_1 + 0xf0) == 0x305e)) {
    uVar4 = 0x1908;
  }
  iVar2 = __mali_pixel_format_get_bpp(*(undefined4 *)(*(int *)(param_1 + 0xb8) + 0x80));
  if ((iVar2 * *(int *)(param_1 + 0xbc) & 0xfffffff8U) < 0x200) {
    uVar4 = 0x3009;
  }
  else {
    iVar3 = (iVar3 + -1) * 0x4c;
    (**(code **)(iVar3 + piVar1[0xc] + 0x24))
              (*(undefined4 *)(*(int *)(*(int *)(param_2 + 4) + 0xc) + 0xc));
    (**(code **)(iVar3 + piVar1[0xc] + 0x3c))();
    iVar2 = mali_frame_builder_get_attachment(*(undefined4 *)(param_1 + 8),0);
    if ((iVar2 == 0) || (iVar2 = mali_render_attachment_get_target(iVar2,0,0), iVar2 == 0))
    goto LAB_409281b4;
    (**(code **)(iVar3 + piVar1[0xc] + 0x44))
              (*(undefined4 *)(*(int *)(*(int *)(param_2 + 4) + 0xc) + 0xc),0xde1,
               *(undefined4 *)(param_1 + 0xdc),uVar4);
    iVar3 = (**(code **)(iVar3 + piVar1[0xc] + 0x3c))();
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0xfc) = 1;
      goto LAB_409281b4;
    }
    if (iVar3 != 0x505) {
      *(undefined4 *)(param_2 + 0x10) = 0x300c;
      goto LAB_409281b4;
    }
    uVar4 = 0x3003;
  }
  *(undefined4 *)(param_2 + 0x10) = uVar4;
LAB_409281b4:
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 409281bc FUN_409281bc */

/* Boundary evidence: original MIPS .pdata 409281bc..40928273. Semantic name remains unreviewed. */

bool FUN_409281bc(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = FUN_409319b8();
  iVar2 = *(int *)(param_1 + 0xb8);
  iVar2 = (**(code **)((*(int *)(*(int *)(*(int *)(param_2 + 4) + 0xc) + 0x18) + -1) * 0x4c +
                       piVar1[0xc] + 0x2c))
                    (*(undefined4 *)(param_2 + 0x1c),*(undefined4 *)(param_1 + 8),
                     *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(iVar2 + 4),
                     *(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0xc),
                     *(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x34),
                     *(undefined4 *)(iVar2 + 0x68),*(undefined4 *)(iVar2 + 100),
                     *(undefined4 *)(iVar2 + 0x60));
  return iVar2 == 0;
}



/* 40928274 FUN_40928274 */

/* Boundary evidence: original MIPS .pdata 40928274..409282eb. Semantic name remains unreviewed. */

void FUN_40928274(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = FUN_409319b8();
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar1 = (*(int *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x18) + -1) * 0x4c;
    (**(code **)(piVar2[0xc] + iVar1 + 0x24))();
    (**(code **)(piVar2[0xc] + iVar1 + 0x20))(0);
  }
  return;
}



/* 409282ec FUN_409282ec */

/* Boundary evidence: original MIPS .pdata 409282ec..4092836b. Semantic name remains unreviewed. */

void FUN_409282ec(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = FUN_409319b8();
  if ((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(param_1 + 4) != 0)) {
    iVar1 = (*(int *)(*(int *)(*(int *)(param_1 + 4) + 0xc) + 0x18) + -1) * 0x4c;
    (**(code **)(iVar1 + piVar2[0xc] + 0x24))();
    (**(code **)(iVar1 + piVar2[0xc] + 0x20))(0);
  }
  return;
}



/* 4092836c FUN_4092836c */

/* Boundary evidence: original MIPS .pdata 4092836c..409283c3. Semantic name remains unreviewed. */

undefined4 FUN_4092836c(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_409319b8();
  if (*(int *)(param_1 + 0xc) != 0) {
    (**(code **)(*(int *)(param_1 + 0x18) * 0x4c + piVar1[0xc] + -0x38))();
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return 1;
}



/* 409283c4 FUN_409283c4 */

/* Boundary evidence: original MIPS .pdata 409283c4..4092845f. Semantic name remains unreviewed. */

undefined4 FUN_409283c4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = FUN_409319b8();
  iVar1 = (*(int *)(param_1 + 0x18) + -1) * 0x4c;
  (**(code **)(piVar2[0xc] + iVar1 + 0x34))(0,0,param_2,param_3);
  (**(code **)(piVar2[0xc] + iVar1 + 0x38))(0,0,param_2,param_3);
  return 1;
}



/* 40928460 FUN_40928460 */

/* Boundary evidence: original MIPS .pdata 40928460..409284f7. Semantic name remains unreviewed. */

void FUN_40928460(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = FUN_409319b8();
  iVar1 = (*(int *)(param_1 + 0x18) + -1) * 0x4c;
  (**(code **)(piVar2[0xc] + iVar1 + 0x34))(0,0,param_2,param_3);
  (**(code **)(piVar2[0xc] + iVar1 + 0x38))(0,0,param_2,param_3);
  return;
}



/* 409284f8 FUN_409284f8 */

/* Boundary evidence: original MIPS .pdata 409284f8..4092865f. Semantic name remains unreviewed. */

undefined4 FUN_409284f8(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = FUN_409319b8();
  if (*(int *)(param_4 + 0xc) != 0x30a0) {
    return 1;
  }
  iVar1 = (*(int *)(param_1 + 0x18) + -1) * 0x4c;
  (**(code **)(piVar2[0xc] + iVar1 + 0x20))(*(undefined4 *)(param_1 + 0xc));
  iVar3 = *(int *)(param_2 + 0xb8);
  iVar3 = (**(code **)(piVar2[0xc] + iVar1 + 0x2c))
                    (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_2 + 8),
                     *(undefined4 *)(param_2 + 0xc),*(undefined4 *)(iVar3 + 4),
                     *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0xc),
                     *(undefined4 *)(iVar3 + 0x14),*(undefined4 *)(iVar3 + 0x34),
                     *(undefined4 *)(iVar3 + 0x68),*(undefined4 *)(iVar3 + 100),
                     *(undefined4 *)(iVar3 + 0x60));
  if ((iVar3 == 0) &&
     (iVar3 = (**(code **)(piVar2[0xc] + iVar1 + 0x30))
                        (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_3 + 8),
                         *(undefined4 *)(param_3 + 0xc)), iVar3 == 0)) {
    if (*(int *)(param_1 + 0x10) != 0) {
      return 1;
    }
    iVar3 = FUN_409283c4(param_1,*(undefined4 *)(param_2 + 0xbc),*(undefined4 *)(param_2 + 0xc0));
    if (iVar3 != 0) {
      *(undefined4 *)(param_1 + 0x10) = 1;
      return 1;
    }
    (**(code **)(piVar2[0xc] + iVar1 + 0x20))(0);
  }
  return 0;
}



/* 40928660 FUN_40928660 */

/* Boundary evidence: original MIPS .pdata 40928660..409287ef. Semantic name remains unreviewed. */

undefined4 * FUN_40928660(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  piVar1 = FUN_409319b8();
  if (param_3 == 1) {
    if ((*(uint *)(param_1 + 0x5c) & 1) != 0) {
      uVar5 = *(uint *)(piVar1[0xc] + 0x10c) & 1;
      goto joined_r0x4092873c;
    }
  }
  else if ((param_3 == 2) && ((*(uint *)(param_1 + 0x5c) & 4) != 0)) {
    uVar5 = *(uint *)(piVar1[0xc] + 0x10c) & 4;
joined_r0x4092873c:
    if (uVar5 != 0) {
      puVar2 = FUN_40931f94(param_1,param_3);
      if (puVar2 != (undefined4 *)0x0) {
        uVar4 = 0;
        if (param_2 != 0) {
          uVar4 = *(undefined4 *)(param_2 + 0xc);
        }
        iVar3 = (**(code **)((param_3 + -1) * 0x4c + piVar1[0xc] + 0x10))
                          (*(undefined4 *)(*(int *)(param_4 + 8) + 0x1c),uVar4,
                           __egl_get_image_ptr_implicit);
        puVar2[3] = iVar3;
        if (iVar3 != 0) {
          puVar2[10] = 0;
          if (param_3 == 1) {
            puVar2[10] = 2;
          }
          else if (param_3 == 2) {
            puVar2[10] = 0x16;
          }
          puVar2[2] = 0x30a0;
          return puVar2;
        }
        *(undefined4 *)(param_4 + 0x10) = 0x3003;
        FUN_409320e4((int)puVar2);
        return (undefined4 *)0x0;
      }
      if (param_4 == 0) {
        return (undefined4 *)0x0;
      }
      uVar4 = 0x3003;
      goto LAB_409286e8;
    }
  }
  if (param_4 == 0) {
    return (undefined4 *)0x0;
  }
  uVar4 = 0x3005;
LAB_409286e8:
  *(undefined4 *)(param_4 + 0x10) = uVar4;
  return (undefined4 *)0x0;
}



/* 409287f0 FUN_409287f0 */

/* Boundary evidence: original MIPS .pdata 409287f0..4092887f. Semantic name remains unreviewed. */

void FUN_409287f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  FUN_40935b30();
  puVar1 = (undefined4 *)FUN_4092c9b0();
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = FUN_4092c808(puVar1,&param_5);
    if (param_5 == 0x30a0) {
      (**(code **)(*(int *)(*(int *)(iVar2 + 0xc) + 0x18) * 0x4c + *(int *)(puVar1[2] + 0x30) + 0xc)
      )(param_1,param_2);
    }
    piVar3 = FUN_409319b8();
    if (piVar3 != (int *)0x0) {
      mali_sys_lock_unlock(piVar3[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x18);
}



/* 40928880 FUN_40928880 */

/* Boundary evidence: original MIPS .pdata 40928880..409288ff. Semantic name remains unreviewed. */

undefined4 FUN_40928880(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  tagRECT tStack_20;
  
  GetClientRect((HWND)*param_1,&tStack_20);
  iVar1 = GetSystemMetrics(0);
  if (((tStack_20.right == iVar1) && (iVar1 = GetSystemMetrics(1), tStack_20.bottom == iVar1)) &&
     (uVar2 = GetWindowLongW((HWND)*param_1,-0x14), (uVar2 & 8) != 0)) {
    return 1;
  }
  return 0;
}



/* 40928910 FUN_40928910 */

/* Boundary evidence: original MIPS .pdata 40928910..4092893f. Semantic name remains unreviewed. */

bool FUN_40928910(HWND param_1)

{
  BOOL BVar1;
  
  BVar1 = IsWindow(param_1);
  return BVar1 != 0;
}



/* 40928940 FUN_40928940 */

/* Boundary evidence: original MIPS .pdata 40928940..40928997. Semantic name remains unreviewed. */

void FUN_40928940(undefined4 *param_1,int *param_2,int *param_3)

{
  tagRECT local_20;
  
  GetClientRect((HWND)*param_1,&local_20);
  *param_2 = local_20.right - local_20.left;
  *param_3 = local_20.bottom - local_20.top;
  return;
}



/* 40928998 FUN_40928998 */

/* Boundary evidence: original MIPS .pdata 40928998..409289c3. Semantic name remains unreviewed. */

void FUN_40928998(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(param_3 + 0x104))(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* 409289c4 FUN_409289c4 */

/* Boundary evidence: original MIPS .pdata 409289c4..409289ef. Semantic name remains unreviewed. */

void FUN_409289c4(void)

{
  NKDbgPrintfW(L"%s %d\r\n",L"src/egl/egl_platform_win32.c",0x8da);
  return;
}



/* 409289f0 FUN_409289f0 */

/* Boundary evidence: original MIPS .pdata 409289f0..40928a1f. Semantic name remains unreviewed. */

undefined4 FUN_409289f0(void)

{
  NKDbgPrintfW(L"%s %d\r\n",L"src/egl/egl_platform_win32.c",0x8d0);
  return 0;
}



/* 40928a20 FUN_40928a20 */

/* Boundary evidence: original MIPS .pdata 40928a20..40928a4b. Semantic name remains unreviewed. */

void FUN_40928a20(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(param_3 + 0x100))(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* 40928a4c FUN_40928a4c */

/* Boundary evidence: original MIPS .pdata 40928a4c..40928b93. Semantic name remains unreviewed. */

void FUN_40928a4c(int param_1,int *param_2)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char acStack_38 [8];
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  int local_20;
  int local_1c;
  
  iVar6 = 0;
  iVar4 = -1;
  do {
    if (iVar4 != -1) break;
    mali_pixel_format_get_bpc
              (iVar6,auStack_24,&local_20,&local_1c,auStack_28,auStack_30,acStack_38 + 4);
    cVar3 = '\0';
    acStack_38[3] = 0;
    iVar4 = 2;
    piVar2 = &local_20;
    do {
      if (*piVar2 == 0) {
        pcVar1 = acStack_38 + iVar4;
        *pcVar1 = '\0';
      }
      else {
        pcVar1 = acStack_38 + iVar4;
        *pcVar1 = (char)piVar2[1] + cVar3;
      }
      cVar3 = *pcVar1 + cVar3;
      prefetch(piVar2 + -2,0);
      iVar4 = iVar4 + -1;
      piVar2 = piVar2 + -1;
    } while (-1 < iVar4);
    iVar5 = 3;
    piVar2 = &local_1c;
    do {
      if (((char)*piVar2 != *(char *)(param_1 + 0x58 + iVar5)) ||
         (acStack_38[iVar5] != *(char *)(iVar5 + param_1 + 0x5c))) {
        iVar4 = -1;
        break;
      }
      iVar5 = iVar5 + -1;
      piVar2 = piVar2 + -1;
      iVar4 = iVar6;
    } while (-1 < iVar5);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 9);
  *param_2 = iVar4;
  return;
}



/* 40928ba4 FUN_40928ba4 */

/* Boundary evidence: original MIPS .pdata 40928ba4..40928c0f. Semantic name remains unreviewed. */

undefined4 FUN_40928ba4(HANDLE param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_68 [4];
  int local_64;
  int local_60;
  
  iVar1 = GetObjectW(param_1,0x54,auStack_68);
  if ((iVar1 == 0x54) && (local_64 == *(int *)(param_2 + 0xbc))) {
    uVar2 = 0;
    if (local_60 == *(int *)(param_2 + 0xc0)) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40928c18 FUN_40928c18 */

/* Boundary evidence: original MIPS .pdata 40928c18..40928c4b. Semantic name remains unreviewed. */

bool FUN_40928c18(HANDLE param_1)

{
  int iVar1;
  undefined1 auStack_60 [88];
  
  iVar1 = GetObjectW(param_1,0x54,auStack_60);
  return iVar1 != 0;
}



/* 40928c4c FUN_40928c4c */

/* Boundary evidence: original MIPS .pdata 40928c4c..40928c9b. Semantic name remains unreviewed. */

void FUN_40928c4c(HANDLE param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 auStack_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  
  iVar1 = GetObjectW(param_1,0x18,auStack_28);
  if (iVar1 != 0) {
    *param_2 = local_24;
    *param_3 = local_20;
  }
  return;
}



/* 40928cc8 FUN_40928cc8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 40928cc8..40928e97. Semantic name remains unreviewed. */

void FUN_40928cc8(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  HANDLE hDevice;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined *lpInBuffer;
  DWORD DStack00000020;
  
  FUN_40935a70();
  DStack00000020 = 0xffffffff;
  FUN_40928a4c(param_3,(int *)&stack0x00000020);
  if (DStack00000020 != 0xffffffff) {
    lpInBuffer = &DAT_40938b40;
    piVar7 = (int *)(param_3 + 0x10);
    iVar6 = 0;
    piVar8 = piVar7;
    do {
      hDevice = DAT_40938afc;
      iVar1 = _DAT_00005b04;
      iVar3 = **(int **)(param_2 + 0xb8);
      if (iVar3 < 0) {
        iVar3 = iVar3 + 7;
      }
      iVar4 = *(int *)(param_2 + 0xc0);
      iVar5 = *(int *)(param_2 + 0xbc);
      *(undefined4 *)(lpInBuffer + 0x14) = 2;
      *(undefined4 *)(lpInBuffer + 0x10) = 2;
      iVar3 = (((iVar3 >> 3) * iVar4 * iVar5 + iVar1) - 1U & ~(iVar1 - 1U)) + 0x8000;
      *(int *)(lpInBuffer + 0xc) = iVar3;
      BVar2 = DeviceIoControl(hDevice,0x220404,lpInBuffer,0x20,(LPVOID)0x0,0,&stack0x00000020,
                              (LPOVERLAPPED)0x0);
      if (BVar2 == 0) {
        NKDbgPrintfW(L"Cannot get memory: %d size:%d\r\n",iVar6,iVar3);
      }
      piVar8[0xb] = 0;
      iVar3 = mali_mem_add_phys_mem
                        (param_4,*(undefined4 *)(lpInBuffer + 8),iVar3,
                         *(undefined4 *)(lpInBuffer + 4));
      piVar8[-4] = iVar3;
      if (iVar3 == 0) goto joined_r0x40928e64;
      iVar3 = mali_shared_mem_ref_alloc_existing_mem(iVar3);
      *piVar8 = iVar3;
      if (iVar3 == 0) goto joined_r0x40928e34;
      iVar6 = iVar6 + 1;
      lpInBuffer = lpInBuffer + 0x20;
      piVar8 = piVar8 + 1;
    } while (iVar6 < 4);
  }
LAB_40928e90:
                    /* WARNING: Subroutine does not return */
  FUN_40935aa8(0x28);
joined_r0x40928e64:
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    mali_shared_mem_ref_owner_deref(*piVar7);
    *piVar7 = 0;
    piVar7[-4] = 0;
    piVar7 = piVar7 + 1;
  }
  goto LAB_40928e90;
joined_r0x40928e34:
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    mali_shared_mem_ref_owner_deref(*piVar7);
    *piVar7 = 0;
    piVar7[-4] = 0;
    piVar7 = piVar7 + 1;
  }
  goto LAB_40928e90;
}



/* 40928e98 FUN_40928e98 */

/* Boundary evidence: original MIPS .pdata 40928e98..40928f1f. Semantic name remains unreviewed. */

void FUN_40928e98(void)

{
  BOOL BVar1;
  int iVar2;
  undefined *lpInBuffer;
  
  FUN_40935ae0();
  lpInBuffer = &DAT_40938b40;
  iVar2 = 0;
  do {
    BVar1 = DeviceIoControl(DAT_40938afc,0x220408,lpInBuffer,0x20,(LPVOID)0x0,0,
                            (LPDWORD)&stack0x00000020,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      NKDbgPrintfW(L"Cannot free memory: %d \r\n",iVar2);
    }
    iVar2 = iVar2 + 1;
    lpInBuffer = lpInBuffer + 0x20;
  } while (iVar2 < 4);
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x28);
}



/* 40928f20 FUN_40928f20 */

/* Boundary evidence: original MIPS .pdata 40928f20..40928f8b. Semantic name remains unreviewed. */

undefined4 FUN_40928f20(HDC param_1)

{
  DWORD DVar1;
  uint uVar2;
  
  if (param_1 != (HDC)0x0) {
    DVar1 = GetObjectType(param_1);
    if ((DVar1 != 3) && (DVar1 != 10)) {
      return 0;
    }
    uVar2 = GetDeviceCaps(param_1,0x26);
    if ((uVar2 & 1) == 0) {
      return 0;
    }
  }
  return 1;
}



/* 40928f9c FUN_40928f9c */

/* Boundary evidence: original MIPS .pdata 40928f9c..40929113. Semantic name remains unreviewed. */

undefined4 FUN_40928f9c(void)

{
  DWORD DVar1;
  LSTATUS LVar2;
  wchar_t *pwVar3;
  HKEY local_18;
  DWORD local_14;
  
  DAT_40938af8 = GetDC((HWND)0x0);
  if (DAT_40938af8 == (HDC)0xffffffff) {
    DVar1 = GetLastError();
    pwVar3 = L"Cannot open LCD1: %d\r\n";
  }
  else {
    DAT_40938afc = CreateFileW(L"MEM1:",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (DAT_40938afc != (HANDLE)0xffffffff) {
      DAT_40938ae4 = 0;
      LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Drivers\\Display\\AU13XXLCD\\Windows\\OpenGL",0,0,
                            &local_18);
      DVar1 = local_14;
      if (LVar2 == 0) {
        local_14 = 4;
        DVar1 = RegQueryValueExW(local_18,L"Index",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&DAT_40938284,
                                 &local_14);
      }
      if (DVar1 != 0) {
        DAT_40938284 = 2;
      }
      NKDbgPrintfW(L"EGL Using Au13XXLCD Overlay #%d\r\n",DAT_40938284);
      RegCloseKey(local_18);
      return 1;
    }
    DVar1 = GetLastError();
    pwVar3 = L"Cannot open MEM1: %d\r\n";
  }
  NKDbgPrintfW(pwVar3,DVar1);
  return 0;
}



/* 40929128 FUN_40929128 */

int FUN_40929128(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 & 0xffff0000) == 0) {
    iVar1 = 0x10;
  }
  else {
    param_1 = param_1 >> 0x10;
  }
  if ((param_1 & 0xff00) == 0) {
    iVar1 = iVar1 + 8;
  }
  else {
    param_1 = param_1 >> 8;
  }
  return (uint)(byte)(&DAT_4092203c)[param_1] + iVar1;
}



/* 40929174 FUN_40929174 */

/* Boundary evidence: original MIPS .pdata 40929174..409291e3. Semantic name remains unreviewed. */

int FUN_40929174(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x34);
  if (iVar1 == 0) {
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      if (*(int *)(param_1 + 0x48) == 0) {
        *(int *)(param_1 + 0x48) = param_1;
      }
      (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x44))
      ;
    }
    mali_surface_free(param_1);
  }
  return iVar1;
}



/* 40929204 FUN_40929204 */

/* Boundary evidence: original MIPS .pdata 40929204..4092921f. Semantic name remains unreviewed. */

void FUN_40929204(int param_1)

{
  mali_sys_atomic_inc(param_1 + 4);
  return;
}



/* 40929220 FUN_40929220 */

/* Boundary evidence: original MIPS .pdata 40929220..40929243. Semantic name remains unreviewed. */

void FUN_40929220(void)

{
  CeGetThreadPriority(0x41);
  return;
}



/* 40929244 FUN_40929244 */

/* Boundary evidence: original MIPS .pdata 40929244..40929293. Semantic name remains unreviewed. */

undefined4 FUN_40929244(void)

{
  DAT_40938b04 = 1;
  EventModify(DAT_40938b08,3);
  WaitForSingleObject(DAT_40938b0c,0xffffffff);
  return DAT_40938b04;
}



/* 40929294 FUN_40929294 */

/* Boundary evidence: original MIPS .pdata 40929294..40929463. Semantic name remains unreviewed. */

void FUN_40929294(void)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  uint uStack00000050;
  int in_stack_00000078;
  
  FUN_40935b30();
  iVar1 = DAT_40938b14;
  uStack00000050 = DAT_4093827c;
  if ((in_stack_00000078 != 0) && (DAT_40938ae4 != 0)) {
    CeGetThreadPriority(0x41);
  }
  uStack00000018 = DAT_40938284;
  uStack0000001c = 0;
  uStack00000020 = (&DAT_40938b48)[*(int *)(iVar1 + 0x28) * 8];
  iVar4 = *(int *)(iVar1 + 0x28) + 1;
  *(int *)(iVar1 + 0x28) = iVar4;
  if (3 < iVar4) {
    *(undefined4 *)(iVar1 + 0x28) = 0;
  }
  ExtEscape(DAT_40938af8,0x229c54,0xc,(LPCSTR)&stack0x00000018,0,(LPSTR)0x0);
  if (DAT_40938b00 == 0) {
    ExtEscape(DAT_40938af8,0x229c44,4,(LPCSTR)&stack0x00000018,0,(LPSTR)0x0);
    DAT_40938b00 = 1;
  }
  if (DAT_409382c8 == 0xffffffff) {
    DAT_409382c8 = GetTickCount();
  }
  else {
    DVar2 = GetTickCount();
    if (DAT_409382c8 + 5000 <= DVar2) {
      DVar2 = GetTickCount();
      if (DAT_40938b18 == 0) {
        trap(0x1c00);
      }
      uVar3 = __ultofp((DVar2 - DAT_409382c8) / DAT_40938b18);
      uVar3 = __fpdiv(0x447a0000,uVar3);
      uVar5 = __fptodp(uVar3);
      sprintf(&stack0x00000028,"eglSwapBuffers: %f FPS\r\n",(int)uVar5,
              (int)((ulonglong)uVar5 >> 0x20));
      NKDbgPrintfW(&DAT_40924868,&stack0x00000028);
      DAT_409382c8 = GetTickCount();
      DAT_40938b18 = 0;
    }
  }
  DAT_40938b18 = DAT_40938b18 + 1;
  FUN_40925f80(uStack00000050);
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x58);
}



/* 40929464 FUN_40929464 */

/* Boundary evidence: original MIPS .pdata 40929464..40929493. Semantic name remains unreviewed. */

bool FUN_40929464(HANDLE param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_40928ba4(param_1,param_2);
  return iVar1 != 0;
}



/* 40929494 FUN_40929494 */

void FUN_40929494(undefined4 param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = DAT_40938b14;
  if ((param_2 != (uint *)0x0) && (DAT_40938b14 != 0)) {
    *param_2 = (uint)*(byte *)(DAT_40938b14 + 0x59);
    param_2[1] = (uint)*(byte *)(iVar1 + 0x5a);
    param_2[2] = (uint)*(byte *)(iVar1 + 0x5b);
    param_2[3] = (uint)*(byte *)(iVar1 + 0x5d);
    param_2[4] = (uint)*(byte *)(iVar1 + 0x5e);
    param_2[5] = (uint)*(byte *)(iVar1 + 0x5f);
  }
  return;
}



/* 409294e4 FUN_409294e4 */

/* Boundary evidence: original MIPS .pdata 409294e4..4092951b. Semantic name remains unreviewed. */

int FUN_409294e4(uint param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0x20;
  }
  else {
    iVar1 = FUN_40929128(-param_1 & param_1);
    iVar1 = 0x1f - iVar1;
  }
  return iVar1;
}



/* 4092951c FUN_4092951c */

/* Boundary evidence: original MIPS .pdata 4092951c..40929563. Semantic name remains unreviewed. */

void FUN_4092951c(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_40935b30();
  uVar1 = mali_pixel_layout_to_texel_layout(0);
  uVar2 = mali_pixel_to_texel_format(param_2);
  *param_1 = param_2;
  param_1[1] = uVar2;
  param_1[2] = 0;
  param_1[3] = uVar1;
  param_1[4] = 0;
                    /* WARNING: Subroutine does not return */
  param_1[5] = 0;
  FUN_40935b50(0x10);
}



/* 40929564 FUN_40929564 */

/* Boundary evidence: original MIPS .pdata 40929564..409296a3. Semantic name remains unreviewed. */

void FUN_40929564(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 in_stack_00000018;
  
  FUN_40935b30();
  FUN_409319b8();
  if (param_1[0x29] == 1) {
    if ((HWND)*param_1 != (HWND)0x0) {
      SendMessageW((HWND)*param_1,0x10,0,0);
    }
  }
  else {
    in_stack_00000018 = DAT_40938284;
    ExtEscape(DAT_40938af8,0x229c50,0x20,(LPCSTR)&stack0x00000018,0,(LPSTR)0x0);
    DAT_40938b00 = 0;
    ExtEscape(DAT_40938af8,0x229c48,4,(LPCSTR)&stack0x00000018,0,(LPSTR)0x0);
  }
  iVar2 = param_1[0x42];
  if (iVar2 != 0) {
    if (param_1[2] != 0) {
      FUN_4092f460(param_1[2]);
    }
    param_1[2] = 0;
    puVar1 = DAT_40938b14;
    if (((*(int *)(iVar2 + 0x74) == 3) || (*(int *)(iVar2 + 0x74) == 2)) &&
       (DAT_40938b14 != (undefined4 *)0x0)) {
      FUN_40928e98();
      *(undefined4 *)(iVar2 + 0x74) = 0;
      if (puVar1[4] != 0) {
        mali_shared_mem_ref_owner_deref();
        *puVar1 = 0;
        puVar1[4] = 0;
      }
      if (puVar1[5] != 0) {
        mali_shared_mem_ref_owner_deref();
        puVar1[1] = 0;
        puVar1[5] = 0;
      }
    }
    mali_sys_free(iVar2);
    param_1[0x42] = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x38);
}



/* 409296a4 FUN_409296a4 */

/* Boundary evidence: original MIPS .pdata 409296a4..40929727. Semantic name remains unreviewed. */

void FUN_409296a4(void)

{
  int iVar1;
  
  FUN_40935b30();
  FUN_409319b8();
  iVar1 = DAT_40938b14;
  if (DAT_40938b14 != 0) {
    DAT_40938b04 = 0;
    EventModify(DAT_40938b08,3);
    mali_osu_wait_for_thread(DAT_40938b10,0);
    DAT_40938b10 = 0;
    CloseHandle(DAT_40938b08);
    CloseHandle(DAT_40938b0c);
    DAT_40938b08 = (HANDLE)0x0;
    DAT_40938b0c = (HANDLE)0x0;
    mali_sys_free(iVar1);
    DAT_40938b14 = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 40929728 FUN_40929728 */

/* Boundary evidence: original MIPS .pdata 40929728..40929833. Semantic name remains unreviewed. */

int FUN_40929728(int param_1,int param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,
                undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int local_40 [2];
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  local_40[0] = -1;
  FUN_40928a4c(param_2,local_40);
  local_38 = local_40[0];
  if (local_40[0] != -1) {
    uVar1 = mali_pixel_layout_to_texel_layout(0);
    local_34 = mali_pixel_to_texel_format(local_38);
    piVar3 = (int *)((param_1 + 4) * 4 + param_2);
    iVar2 = *piVar3;
    local_30 = 0;
    local_28 = 0;
    local_24 = 0;
    if (iVar2 != 0) {
      local_2c = uVar1;
      iVar2 = mali_surface_alloc_ref(param_3,param_4,param_5,&local_38,iVar2,param_6,param_7);
      if (iVar2 == 0) {
        return 0;
      }
      mali_sys_atomic_inc(*piVar3 + 4);
      *(undefined4 *)(iVar2 + 0x3c) = 1;
      return iVar2;
    }
  }
  return 0;
}



/* 40929834 FUN_40929834 */

/* Boundary evidence: original MIPS .pdata 40929834..409298ef. Semantic name remains unreviewed. */

bool FUN_40929834(uint param_1,undefined1 *param_2,undefined1 *param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 != 0) {
    iVar2 = FUN_40929128(-param_1 & param_1);
    uVar3 = 0x1f - iVar2;
    if (uVar3 != 0x20) goto LAB_40929888;
  }
  uVar3 = 0;
LAB_40929888:
  iVar2 = FUN_40929128(param_1);
  uVar4 = (0x20 - (uVar3 & 0xff)) - iVar2;
  bVar1 = param_1 == (1 << (uVar4 & 0x1f)) + -1 << (uVar3 & 0x1f);
  if (bVar1) {
    *param_2 = (char)uVar4;
    *param_3 = (char)uVar3;
  }
  return bVar1;
}



/* 409298f0 FUN_409298f0 */

/* Boundary evidence: original MIPS .pdata 409298f0..40929c2f. Semantic name remains unreviewed. */

void FUN_409298f0(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int in_stack_00000020;
  uint in_stack_00000024;
  int in_stack_00000030;
  undefined4 in_stack_00000040;
  uint in_stack_00000044;
  uint in_stack_00000048;
  uint in_stack_0000004c;
  undefined4 in_stack_00000050;
  undefined4 in_stack_00000054;
  undefined4 in_stack_00000058;
  
  FUN_40935a70();
  memset(&stack0x00000030,0,0x10);
  GetWindowRect((HWND)*param_1,(LPRECT)&stack0x00000020);
  if (in_stack_00000020 < 0) {
    in_stack_00000020 = 0;
  }
  if ((int)in_stack_00000024 < 0) {
    in_stack_00000024 = 0;
  }
  FUN_409319b8();
  iVar1 = mali_sys_malloc(0x78);
  if (iVar1 == 0) goto LAB_40929c24;
  param_1[0x42] = iVar1;
  if (param_1[0x29] != 0) {
    SetWindowLongW((HWND)*param_1,0,(LONG)param_1);
  }
  *(undefined4 *)(iVar1 + 0x74) = 0;
  pcVar2 = (char *)mali_sys_config_string_get("MALI_SINGLEBUFFER");
  if (pcVar2 != (char *)0x0) {
    if (*pcVar2 != '0') {
      param_1[0x39] = 0x3085;
    }
    mali_sys_config_string_release(pcVar2);
  }
  iVar7 = 4;
  iVar3 = FUN_40928cc8(4,(int)param_1,param_3,param_2);
  if (iVar3 == 1) {
    iVar3 = 0;
    piVar8 = &stack0x00000030;
    puVar10 = (undefined4 *)(param_3 + 0x3c);
    do {
      iVar4 = FUN_40929728(iVar3,param_3,(short)param_1[0x2f],(short)param_1[0x30],
                           (short)*(undefined4 *)(param_3 + 0x4c),*puVar10,param_2);
      iVar3 = iVar3 + 1;
      *piVar8 = iVar4;
      piVar8 = piVar8 + 1;
      puVar10 = puVar10 + 1;
    } while (iVar3 < 4);
    if (iVar3 == 4) {
      param_1[0x40] = FUN_40929294;
      param_1[4] = 1;
      *(undefined4 *)(iVar1 + 0x74) = 3;
      goto LAB_40929a4c;
    }
  }
  else {
LAB_40929a4c:
    param_1[0x39] = 0x3084;
    iVar3 = FUN_4092e7a8(param_2,param_1[0x2e],(int)&stack0x00000030);
    param_1[2] = iVar3;
    if (iVar3 != 0) {
      uVar5 = mali_frame_builder_get_attachment(iVar3,0);
      *(undefined2 *)((int)param_1 + 0x72) = 4;
      puVar9 = &stack0x00000030;
      puVar10 = param_1 + 8;
      do {
        mali_render_attachment_set_target(uVar5,0,*puVar9,0);
        uVar6 = mali_render_attachment_get_target(uVar5,0,0);
        iVar7 = iVar7 + -1;
        puVar10[-3] = uVar6;
        puVar10[-2] = param_1;
        *(undefined2 *)puVar10 = 0;
        puVar10[-1] = 0;
        puVar10 = puVar10 + 5;
        puVar9 = puVar9 + 1;
      } while (iVar7 != 0);
      mali_render_attachment_set_target(uVar5,0,in_stack_00000030,0);
      *(undefined4 *)(iVar1 + 0x6c) = 0;
      *(undefined4 *)(iVar1 + 0x70) = 1;
      in_stack_00000048 = 0x18000000;
      if (((int *)param_1[0x2e])[0x20] == 0) {
        in_stack_00000048 = 0xc000000;
      }
      in_stack_00000040 = DAT_40938284;
      in_stack_00000054 = 0;
      in_stack_00000044 = (in_stack_00000020 << 0xb | in_stack_00000024) << 10 | 0x1ec;
      in_stack_00000048 = (param_1[0x2f] - 1 | 0x800) << 0xb | param_1[0x30] - 1 | in_stack_00000048
      ;
      iVar1 = *(int *)param_1[0x2e];
      if (iVar1 < 0) {
        iVar1 = iVar1 + 7;
      }
      in_stack_0000004c = ((iVar1 >> 3) * param_1[0x2f] | 0x30000U) << 8;
      iVar1 = FUN_40928880(param_1);
      if (iVar1 == 1) {
        in_stack_0000004c = in_stack_0000004c & 0xfcffffff;
      }
      else {
        in_stack_0000004c = in_stack_0000004c | 0x3000000;
      }
      in_stack_00000058 = *param_1;
      in_stack_00000050 = 0;
      ExtEscape(DAT_40938af8,0x229c4c,0x20,(LPCSTR)&stack0x00000040,0,(LPSTR)0x0);
      goto LAB_40929c24;
    }
  }
  piVar8 = &stack0x00000030;
  do {
    if (*piVar8 != 0) {
      FUN_40929174(*piVar8);
      *piVar8 = 0;
    }
    iVar7 = iVar7 + -1;
    piVar8 = piVar8 + 1;
  } while (iVar7 != 0);
  FUN_40928e98();
  mali_sys_free(param_1[0x42]);
  param_1[0x42] = 0;
LAB_40929c24:
                    /* WARNING: Subroutine does not return */
  FUN_40935aa8(0x60);
}



/* 40929c30 FUN_40929c30 */

/* Boundary evidence: original MIPS .pdata 40929c30..40929d67. Semantic name remains unreviewed. */

undefined4 FUN_40929c30(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (DAT_40938b14 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)mali_sys_malloc(0x60);
    if (puVar1 != (undefined4 *)0x0) {
      mali_sys_memset(puVar1,0,0x60);
      puVar1[8] = 0;
      puVar1[9] = 1;
      puVar1[10] = 0;
      FUN_40929834(DAT_409382b8,(undefined1 *)((int)puVar1 + 0x59),
                   (undefined1 *)((int)puVar1 + 0x5d));
      FUN_40929834(DAT_409382bc,(undefined1 *)((int)puVar1 + 0x5a),
                   (undefined1 *)((int)puVar1 + 0x5e));
      FUN_40929834(DAT_409382c0,(undefined1 *)((int)puVar1 + 0x5b),
                   (undefined1 *)((int)puVar1 + 0x5f));
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      DAT_40938b14 = puVar1;
      DAT_40938b08 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      DAT_40938b0c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      if ((DAT_40938b08 != (HANDLE)0x0) && (DAT_40938b0c != (HANDLE)0x0)) {
        return 1;
      }
      mali_sys_free(puVar1);
      DAT_40938b14 = (undefined4 *)0x0;
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 40929d68 FUN_40929d68 */

/* Boundary evidence: original MIPS .pdata 40929d68..40929fc3. Semantic name remains unreviewed. */

int FUN_40929d68(undefined1 *param_1,HANDLE param_2)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined1 uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  undefined1 auStack_88 [18];
  ushort local_76;
  ushort local_62;
  int local_60;
  int local_50;
  uint local_40 [3];
  undefined4 local_34;
  undefined1 auStack_31 [9];
  uint local_28;
  uint local_24;
  
  local_24 = DAT_4093827c;
  iVar2 = GetObjectW(param_2,0x58,auStack_88);
  if (iVar2 == 0x18) {
    if ((((local_76 == 0) || (local_76 < 3)) || (local_76 == 4)) || (local_76 == 8))
    goto LAB_40929f90;
    if (local_76 == 0x10) {
LAB_40929e88:
      uVar3 = 5;
      param_1[5] = 10;
      *(undefined4 *)(param_1 + 8) = 0x10;
      goto LAB_40929e50;
    }
    if (local_76 != 0x18) {
      if (local_76 != 0x20) goto LAB_40929f90;
      goto LAB_40929e48;
    }
LAB_40929e80:
    *(undefined4 *)(param_1 + 8) = 0x18;
  }
  else {
    uVar6 = 0;
    if (iVar2 != 0x54) {
      if (iVar2 != 0x58) goto LAB_40929f90;
      if ((local_60 == 6) && (uVar6 = local_34, local_50 == 4)) {
        local_50 = 3;
      }
    }
    local_28 = (uint)local_62;
    if ((local_28 < 9) || ((local_50 != 3 && (local_50 != 0)))) {
LAB_40929f90:
      FUN_40925f80(local_24);
      return 0;
    }
    if (local_60 != 0) {
      if ((local_60 == 6) || (local_60 == 3)) {
        puVar5 = local_40;
        iVar2 = 3;
        do {
          iVar4 = iVar2;
          bVar1 = FUN_40929834(*puVar5,(undefined1 *)((int)register0x00000074 + -0x31) + iVar4 + 1,
                               (undefined1 *)((int)register0x00000074 + -0x31) + iVar4 + 5);
          iVar2 = CONCAT31(extraout_var,bVar1);
          if (iVar2 != 1) goto LAB_40929f0c;
          puVar5 = puVar5 + -1;
          iVar2 = iVar4 + -1;
        } while (0 < iVar4 + -1);
        bVar1 = FUN_40929834(uVar6,(undefined1 *)((int)register0x00000074 + -0x31) + iVar4,
                             (undefined1 *)((int)register0x00000074 + -0x31) + iVar4 + 4);
        iVar2 = CONCAT31(extraout_var_00,bVar1);
        if (iVar2 == 1) {
          mali_sys_memcpy(param_1,(undefined1 *)((int)register0x00000074 + -0x31) + 1,0xc);
          FUN_40925f80(local_24);
          return 1;
        }
LAB_40929f0c:
        FUN_40925f80(local_24);
        return iVar2;
      }
      goto LAB_40929f90;
    }
    if (local_28 == 0x10) goto LAB_40929e88;
    if (local_28 == 0x18) goto LAB_40929e80;
    if (local_28 != 0x20) goto LAB_40929f90;
LAB_40929e48:
    *(undefined4 *)(param_1 + 8) = 0x20;
  }
  uVar3 = 8;
  param_1[5] = 0x10;
LAB_40929e50:
  *param_1 = 0;
  param_1[1] = uVar3;
  param_1[2] = uVar3;
  param_1[3] = uVar3;
  param_1[4] = 0;
  param_1[6] = uVar3;
  param_1[7] = 0;
  FUN_40925f80(local_24);
  return 1;
}



/* 40929fc4 FUN_40929fc4 */

/* Boundary evidence: original MIPS .pdata 40929fc4..4092a0a3. Semantic name remains unreviewed. */

undefined4 FUN_40929fc4(HANDLE param_1,int *param_2)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  byte local_20 [12];
  uint local_14;
  
  local_14 = DAT_4093827c;
  iVar3 = 0;
  iVar1 = FUN_40929d68(local_20,param_1);
  if (iVar1 != 0) {
    iVar1 = 3;
    do {
      pbVar2 = local_20 + iVar1;
      iVar1 = iVar1 + -1;
      iVar3 = (uint)*pbVar2 + iVar3;
    } while (-1 < iVar1);
    if ((((iVar3 == *param_2) && ((uint)local_20[1] == param_2[1])) &&
        ((uint)local_20[2] == param_2[2])) &&
       ((((uint)local_20[3] == param_2[3] && ((uint)local_20[0] == param_2[5])) && (param_2[4] == 0)
        ))) {
      FUN_40925f80(local_14);
      return 1;
    }
  }
  FUN_40925f80(local_14);
  return 0;
}



/* 4092a0a4 FUN_4092a0a4 */

/* Boundary evidence: original MIPS .pdata 4092a0a4..4092a10b. Semantic name remains unreviewed. */

undefined4 FUN_4092a0a4(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_40938b14 == 0) {
    uVar1 = 0;
  }
  else {
    if ((-1 < (int)param_1[3]) && ((int)param_1[3] < 3)) {
      uVar1 = FUN_409298f0(param_1,param_3,DAT_40938b14);
    }
    param_1[0x41] = FUN_409289c4;
  }
  return uVar1;
}



/* 4092a10c FUN_4092a10c */

/* Boundary evidence: original MIPS .pdata 4092a10c..4092a147. Semantic name remains unreviewed. */

void FUN_4092a10c(void)

{
  FUN_409319b8();
  FUN_40929c30();
  return;
}



/* 4092a148 __egl_build_info */

char * __egl_build_info(void)

{
                    /* 0xa148  1  __egl_build_info */
  return "egl:  ";
}



/* 4092a154 mali_egl_image_get_error */

/* Boundary evidence: original MIPS .pdata 4092a154..4092a16f. Semantic name remains unreviewed. */

void mali_egl_image_get_error(void)

{
                    /* 0xa154  43  mali_egl_image_get_error */
  mali_sys_thread_key_get_data(6);
  return;
}



/* 4092a170 FUN_4092a170 */

/* Boundary evidence: original MIPS .pdata 4092a170..4092a18f. Semantic name remains unreviewed. */

void FUN_4092a170(undefined4 param_1)

{
  mali_sys_thread_key_set_data(6,param_1);
  return;
}



/* 4092a198 FUN_4092a198 */

/* Boundary evidence: original MIPS .pdata 4092a198..4092a2eb. Semantic name remains unreviewed. */

int FUN_4092a198(undefined4 param_1,int param_2,int *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  bVar1 = false;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 4;
  if (param_2 != 0) {
    piVar4 = (int *)(param_2 + 4);
    do {
      iVar3 = piVar4[-1];
      if (iVar3 == 0) {
LAB_4092a208:
        bVar1 = true;
      }
      else if (iVar3 == 0xfa) {
        iVar3 = *piVar4;
        if ((iVar3 < 0) || (0xc < iVar3)) {
LAB_4092a2d8:
          uVar2 = 0x4006;
LAB_4092a2dc:
          mali_sys_thread_key_set_data(6,uVar2);
          return 0;
        }
        *param_3 = iVar3;
      }
      else if (iVar3 == 0xfb) {
        iVar3 = *piVar4;
        if ((iVar3 < 0x100) || (0x104 < iVar3)) goto LAB_4092a2d8;
        param_3[1] = iVar3 + -0x100;
      }
      else {
        if (iVar3 != 0xfc) {
          if (iVar3 != 0x3038) {
            uVar2 = 0x4008;
            goto LAB_4092a2dc;
          }
          goto LAB_4092a208;
        }
        iVar3 = *piVar4;
        if (iVar3 == 1) {
          param_3[2] = 1;
        }
        else if (iVar3 == 2) {
          param_3[2] = 2;
        }
        else {
          if (iVar3 != 4) goto LAB_4092a2d8;
          param_3[2] = 4;
        }
      }
      prefetch(piVar4 + 3,0);
      piVar4 = piVar4 + 2;
    } while (!bVar1);
  }
  iVar3 = mali_image_get_buffer(param_1,param_3[1],*param_3,1);
  if (iVar3 == 0) {
    mali_sys_thread_key_set_data(6,0x4005);
  }
  return iVar3;
}



/* 4092a2ec FUN_4092a2ec */

/* Boundary evidence: original MIPS .pdata 4092a2ec..4092a36b. Semantic name remains unreviewed. */

undefined4 FUN_4092a2ec(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_4092bfc8(param_1,0,5);
  if ((uVar1 == 0) || ((uVar1 | 0x10000000) == 0)) {
    uVar3 = 0x4009;
  }
  else {
    iVar2 = mali_sys_lock_try_lock(*(undefined4 *)(param_1 + 0x1c));
    if (iVar2 != 0) {
      return 1;
    }
    FUN_4092acf0(param_1);
    uVar3 = 0x4003;
  }
  mali_sys_thread_key_set_data(6,uVar3);
  return 0;
}



/* 4092a36c mali_egl_image_wait_sync */

/* WARNING: Removing unreachable block (ram,0x4092a3f8) */
/* Boundary evidence: original MIPS .pdata 4092a36c..4092a43f. Semantic name remains unreviewed. */

void mali_egl_image_wait_sync(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  
                    /* 0xa36c  53  mali_egl_image_wait_sync */
  FUN_40935ae0();
  bVar1 = true;
  mali_sys_thread_key_set_data(6,0x4001);
  iVar2 = FUN_4092a2ec(param_1);
  if (iVar2 != 0) {
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x10);
    mali_sys_get_time_usec();
LAB_4092a3bc:
    do {
      iVar2 = mali_surface_lock_sync_handle(uVar3);
      if (iVar2 == 1) {
        mali_surface_unlock_sync_handle(uVar3);
        goto LAB_4092a434;
      }
      mali_sys_yield();
      uVar4 = mali_sys_get_time_usec();
      if (param_2 != 0) {
        if (uVar4 <= (ulonglong)(longlong)(int)param_2) {
          bVar1 = true;
          goto LAB_4092a3bc;
        }
        bVar1 = false;
      }
    } while (bVar1);
    mali_sys_thread_key_set_data(6,0x4010);
  }
LAB_4092a434:
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x10);
}



/* 4092a440 mali_egl_image_set_sync */

/* Boundary evidence: original MIPS .pdata 4092a440..4092a4af. Semantic name remains unreviewed. */

undefined4 mali_egl_image_set_sync(int param_1)

{
  int iVar1;
  
                    /* 0xa440  50  mali_egl_image_set_sync */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4092a2ec(param_1);
  if (iVar1 != 0) {
    iVar1 = mali_surface_lock_sync_handle(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x10));
    if (iVar1 != 0) {
      return 1;
    }
    mali_sys_thread_key_set_data(6,0x4003);
  }
  return 0;
}



/* 4092a4b0 mali_egl_image_create_sync */

/* Boundary evidence: original MIPS .pdata 4092a4b0..4092a4f7. Semantic name remains unreviewed. */

bool mali_egl_image_create_sync(int param_1)

{
  int iVar1;
  
                    /* 0xa4b0  39  mali_egl_image_create_sync */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4092a2ec(param_1);
  return iVar1 != 0;
}



/* 4092a4f8 mali_egl_image_get_buffer_layout */

/* Boundary evidence: original MIPS .pdata 4092a4f8..4092a5af. Semantic name remains unreviewed. */

void mali_egl_image_get_buffer_layout(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
                    /* 0xa4f8  41  mali_egl_image_get_buffer_layout */
  FUN_40935b30();
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4092a2ec(param_1);
  if ((iVar1 != 0) &&
     (iVar1 = FUN_4092a198(*(undefined4 *)(param_1 + 0x20),param_2,(int *)&stack0x00000010),
     iVar1 != 0)) {
    if (param_3 == (undefined4 *)0x0) {
      mali_sys_thread_key_set_data(6,0x4008);
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x1c);
      if (iVar1 == 0) {
        *param_3 = 0x110;
      }
      else if (iVar1 == 1) {
        *param_3 = 0x111;
      }
      else if (iVar1 == 2) {
        *param_3 = 0x112;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x20);
}



/* 4092a5b0 mali_egl_image_get_buffer_height */

/* Boundary evidence: original MIPS .pdata 4092a5b0..4092a633. Semantic name remains unreviewed. */

void mali_egl_image_get_buffer_height(int param_1,int param_2,uint *param_3)

{
  int iVar1;
  
                    /* 0xa5b0  40  mali_egl_image_get_buffer_height */
  FUN_40935b30();
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4092a2ec(param_1);
  if ((iVar1 != 0) &&
     (iVar1 = FUN_4092a198(*(undefined4 *)(param_1 + 0x20),param_2,(int *)&stack0x00000010),
     iVar1 != 0)) {
    if (param_3 == (uint *)0x0) {
      mali_sys_thread_key_set_data(6,0x4008);
    }
    else {
      *param_3 = (uint)*(ushort *)(iVar1 + 0xe);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x20);
}



/* 4092a634 mali_egl_image_get_buffer_width */

/* Boundary evidence: original MIPS .pdata 4092a634..4092a6b7. Semantic name remains unreviewed. */

void mali_egl_image_get_buffer_width(int param_1,int param_2,uint *param_3)

{
  int iVar1;
  
                    /* 0xa634  42  mali_egl_image_get_buffer_width */
  FUN_40935b30();
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4092a2ec(param_1);
  if ((iVar1 != 0) &&
     (iVar1 = FUN_4092a198(*(undefined4 *)(param_1 + 0x20),param_2,(int *)&stack0x00000010),
     iVar1 != 0)) {
    if (param_3 == (uint *)0x0) {
      mali_sys_thread_key_set_data(6,0x4008);
    }
    else {
      *param_3 = (uint)*(ushort *)(iVar1 + 0xc);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x20);
}



/* 4092a6b8 mali_egl_image_unmap_buffer */

/* Boundary evidence: original MIPS .pdata 4092a6b8..4092a77f. Semantic name remains unreviewed. */

undefined4 mali_egl_image_unmap_buffer(int param_1,int param_2)

{
  int iVar1;
  undefined2 local_20 [2];
  undefined2 local_1c;
  
                    /* 0xa6b8  52  mali_egl_image_unmap_buffer */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4092a2ec(param_1);
  if ((iVar1 != 0) &&
     (iVar1 = FUN_4092a198(*(undefined4 *)(param_1 + 0x20),param_2,(int *)local_20), iVar1 != 0)) {
    iVar1 = mali_image_unlock(*(undefined4 *)(param_1 + 0x20),local_1c,local_20[0],0,0,
                              *(undefined2 *)(iVar1 + 0xc),*(undefined2 *)(iVar1 + 0xe),
                              *(undefined4 *)(param_1 + 0x24));
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
      return 1;
    }
    mali_sys_thread_key_set_data(6,0x4004);
  }
  return 0;
}



/* 4092a780 mali_egl_image_map_buffer */

/* Boundary evidence: original MIPS .pdata 4092a780..4092a89f. Semantic name remains unreviewed. */

void mali_egl_image_map_buffer(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iStack00000030;
  undefined4 uStack00000034;
  undefined2 in_stack_00000038;
  undefined2 in_stack_0000003c;
  undefined4 in_stack_00000040;
  
                    /* 0xa780  48  mali_egl_image_map_buffer */
  FUN_40935b30();
  iStack00000030 = 0;
  uStack00000034 = 0;
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4092a2ec(param_1);
  if ((iVar1 == 0) ||
     (iVar1 = FUN_4092a198(*(undefined4 *)(param_1 + 0x20),param_2,(int *)&stack0x00000038),
     iVar1 == 0)) goto LAB_4092a898;
  iVar1 = mali_image_lock(*(undefined4 *)(param_1 + 0x20),in_stack_00000040,in_stack_0000003c,
                          in_stack_00000038);
  if (iVar1 == 2) {
    uVar2 = 0x4005;
LAB_4092a87c:
    mali_sys_thread_key_set_data(6,uVar2);
  }
  else if (2 < iVar1) {
    if (iVar1 < 5) {
      uVar2 = 0x4004;
    }
    else if (iVar1 == 5) {
      uVar2 = 0x4007;
    }
    else {
      if (iVar1 != 6) goto LAB_4092a884;
      uVar2 = 0x4008;
    }
    goto LAB_4092a87c;
  }
LAB_4092a884:
  if (iStack00000030 != 0) {
    *(int *)(param_1 + 0x24) = iStack00000030;
  }
LAB_4092a898:
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x48);
}



/* 4092a8a0 mali_egl_image_get_format */

/* Boundary evidence: original MIPS .pdata 4092a8a0..4092a933. Semantic name remains unreviewed. */

undefined4 mali_egl_image_get_format(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
                    /* 0xa8a0  44  mali_egl_image_get_format */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4092a2ec(param_1);
  if (iVar1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x20) + 0x108);
      if (puVar2 == (undefined4 *)0x0) {
        *param_2 = 0x3038;
      }
      else {
        *param_2 = *puVar2;
      }
      return 1;
    }
    mali_sys_thread_key_set_data(6,0x4008);
  }
  return 0;
}



/* 4092a934 mali_egl_image_get_height */

/* Boundary evidence: original MIPS .pdata 4092a934..4092a9af. Semantic name remains unreviewed. */

undefined4 mali_egl_image_get_height(int param_1,undefined4 *param_2)

{
  int iVar1;
  
                    /* 0xa934  45  mali_egl_image_get_height */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4092a2ec(param_1);
  if (iVar1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
      return 1;
    }
    mali_sys_thread_key_set_data(6,0x4008);
  }
  return 0;
}



/* 4092a9b0 mali_egl_image_get_width */

/* Boundary evidence: original MIPS .pdata 4092a9b0..4092aa2b. Semantic name remains unreviewed. */

undefined4 mali_egl_image_get_width(int param_1,undefined4 *param_2)

{
  int iVar1;
  
                    /* 0xa9b0  46  mali_egl_image_get_width */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4092a2ec(param_1);
  if (iVar1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = **(undefined4 **)(param_1 + 0x20);
      return 1;
    }
    mali_sys_thread_key_set_data(6,0x4008);
  }
  return 0;
}



/* 4092aa2c mali_egl_image_set_data */

/* Boundary evidence: original MIPS .pdata 4092aa2c..4092ab13. Semantic name remains unreviewed. */

undefined4 mali_egl_image_set_data(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_28;
  undefined4 local_24;
  
                    /* 0xaa2c  49  mali_egl_image_set_data */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4092a2ec(param_1);
  if ((iVar1 != 0) &&
     (iVar1 = FUN_4092a198(*(undefined4 *)(param_1 + 0x20),param_2,&local_28), iVar1 != 0)) {
    iVar1 = mali_image_set_data(*(undefined4 *)(param_1 + 0x20),local_24,local_28,param_3);
    if (iVar1 == 0) {
      return 1;
    }
    if ((iVar1 == 1) || (iVar1 == 2)) {
      uVar2 = 0x4005;
    }
    else if (iVar1 == 5) {
      uVar2 = 0x4007;
    }
    else {
      if (iVar1 != 6) {
        return 0;
      }
      uVar2 = 0x4008;
    }
    mali_sys_thread_key_set_data(6,uVar2);
  }
  return 0;
}



/* 4092ab14 mali_egl_image_unlock_ptr */

/* Boundary evidence: original MIPS .pdata 4092ab14..4092abab. Semantic name remains unreviewed. */

undefined4
mali_egl_image_unlock_ptr(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  undefined4 unaff_s0;
  undefined4 unaff_retaddr;
  
                    /* 0xab14  51  mali_egl_image_unlock_ptr */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar2 = FUN_4092b908(param_1);
  if (iVar2 == 0) {
    uVar3 = 0x4002;
  }
  else {
    mali_image_unlock_all_sessions(*(undefined4 *)(iVar2 + 0x20));
    *(undefined4 *)(iVar2 + 0x24) = 0xffffffff;
    bVar1 = FUN_4092acf0(iVar2);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      if (*(int *)(iVar2 + 0x14) == 0) {
        FUN_4092afc4(iVar2,0,param_3,param_4,unaff_s0,unaff_retaddr);
      }
      return 1;
    }
    uVar3 = 0x4003;
  }
  mali_sys_thread_key_set_data(6,uVar3);
  return 0;
}



/* 4092abac mali_egl_image_lock_ptr */

/* Boundary evidence: original MIPS .pdata 4092abac..4092ac7b. Semantic name remains unreviewed. */

int mali_egl_image_lock_ptr(uint param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
                    /* 0xabac  47  mali_egl_image_lock_ptr */
  mali_sys_thread_key_set_data(6,0x4001);
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    iVar1 = FUN_4092b908(param_1);
    if (iVar1 != 0) {
      iVar3 = mali_sys_lock_try_lock(*(undefined4 *)(iVar1 + 0x1c));
      if (iVar3 == 0) {
        piVar2 = FUN_409319b8();
        if (piVar2 == (int *)0x0) {
          return iVar1;
        }
        mali_sys_lock_unlock(piVar2[5]);
        return iVar1;
      }
      piVar2 = FUN_409319b8();
      if (piVar2 != (int *)0x0) {
        mali_sys_lock_unlock(piVar2[5]);
      }
      uVar4 = 0x4003;
      goto LAB_4092abdc;
    }
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  uVar4 = 0x4002;
LAB_4092abdc:
  mali_sys_thread_key_set_data(6,uVar4);
  return 0;
}



/* 4092ac7c FUN_4092ac7c */

/* Boundary evidence: original MIPS .pdata 4092ac7c..4092acef. Semantic name remains unreviewed. */

undefined4 * FUN_4092ac7c(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)mali_sys_malloc(0x28);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 1;
    *puVar1 = 0;
    puVar1[6] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0xffffffff;
    iVar2 = mali_sys_lock_create();
    puVar1[7] = iVar2;
    if (iVar2 != 0) {
      return puVar1;
    }
    mali_sys_free(puVar1);
  }
  return (undefined4 *)0x0;
}



/* 4092acf0 FUN_4092acf0 */

/* Boundary evidence: original MIPS .pdata 4092acf0..4092ad37. Semantic name remains unreviewed. */

bool FUN_4092acf0(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_lock_try_lock(*(undefined4 *)(param_1 + 0x1c));
  mali_sys_lock_unlock(*(undefined4 *)(param_1 + 0x1c));
  return iVar1 != 0;
}



/* 4092ad38 FUN_4092ad38 */

/* Boundary evidence: original MIPS .pdata 4092ad38..4092ad67. Semantic name remains unreviewed. */

bool FUN_4092ad38(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_lock_try_lock(*(undefined4 *)(param_1 + 0x1c));
  return iVar1 == 0;
}



/* 4092ad68 FUN_4092ad68 */

/* Boundary evidence: original MIPS .pdata 4092ad68..4092ae0b. Semantic name remains unreviewed. */

bool FUN_4092ad68(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_20 [8];
  
  piVar1 = FUN_409319b8();
  iVar2 = piVar1[0x12];
  __mali_named_list_lock(iVar2);
  piVar1 = (int *)__mali_named_list_iterate_begin(iVar2,auStack_20);
  while ((piVar1 != (int *)0x0 && ((param_4 != *piVar1 || (param_3 != piVar1[1]))))) {
    piVar1 = (int *)__mali_named_list_iterate_next(iVar2,auStack_20);
  }
  __mali_named_list_unlock(iVar2);
  return piVar1 != (int *)0x0;
}



/* 4092ae0c __egl_get_image_ptr_implicit */

/* Boundary evidence: original MIPS .pdata 4092ae0c..4092ae3f. Semantic name remains unreviewed. */

int __egl_get_image_ptr_implicit(uint param_1)

{
  int iVar1;
  
                    /* 0xae0c  2  __egl_get_image_ptr_implicit */
  iVar1 = FUN_4092b908(param_1);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x14) == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 4092ae40 FUN_4092ae40 */

/* Boundary evidence: original MIPS .pdata 4092ae40..4092aeab. Semantic name remains unreviewed. */

void FUN_4092ae40(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_s0;
  undefined4 unaff_retaddr;
  
  if (*(int *)(param_1 + 0x20) != 0) {
    mali_image_release();
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  FUN_4092bd54(param_1,0,5,param_4,unaff_s0,unaff_retaddr);
  if (*(int *)(param_1 + 0x18) != 0) {
    mali_sys_free();
  }
  mali_sys_lock_destroy(*(undefined4 *)(param_1 + 0x1c));
  mali_sys_free(param_1);
  return;
}



/* 4092aeac FUN_4092aeac */

/* Boundary evidence: original MIPS .pdata 4092aeac..4092af27. Semantic name remains unreviewed. */

void FUN_4092aeac(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  bVar1 = true;
  uVar3 = 0x10;
  do {
    iVar4 = 0xc;
    do {
      piVar2 = (int *)(*(int *)(param_1 + 0x20) + uVar3);
      if (param_2 == *piVar2) {
        *piVar2 = 0;
      }
      if (*(int *)(*(int *)(param_1 + 0x20) + uVar3) != 0) {
        bVar1 = false;
      }
      iVar4 = iVar4 + -1;
      uVar3 = uVar3 + 4;
    } while (iVar4 != 0);
  } while (uVar3 < 0x100);
  if (bVar1) {
    FUN_4092ae40(param_1,param_2,param_3,param_4);
  }
  return;
}



/* 4092af28 FUN_4092af28 */

/* Boundary evidence: original MIPS .pdata 4092af28..4092afc3. Semantic name remains unreviewed. */

void FUN_4092af28(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  FUN_40935a10();
  iVar4 = *(int *)(param_1 + 0x20);
  uVar3 = 0;
  piVar1 = (int *)(iVar4 + 0x10);
  do {
    uVar2 = 0;
    do {
      if (*piVar1 != 0) {
        if (param_2 == 1) {
          mali_image_set_destroy_callback(iVar4,uVar3,uVar2,0);
        }
        else {
          mali_image_set_destroy_callback(iVar4,uVar3,uVar2,FUN_4092aeac);
        }
      }
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (uVar2 < 0xc);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 5);
                    /* WARNING: Subroutine does not return */
  FUN_40935a40(0x18);
}



/* 4092afc4 FUN_4092afc4 */

/* Boundary evidence: original MIPS .pdata 4092afc4..4092b0c3. Semantic name remains unreviewed. */

void FUN_4092afc4(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_40935b30();
  mali_image_unlock_all_sessions(*(undefined4 *)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  if (param_2 == 1) {
    FUN_4092acf0(param_1);
  }
  iVar1 = mali_sys_lock_try_lock(*(undefined4 *)(param_1 + 0x1c));
  if (iVar1 == 0) {
    FUN_4092acf0(param_1);
    if (*(int *)(param_1 + 0x20) == 0) {
      FUN_4092bd54(param_1,0,5,param_4,param_5,param_6);
      if (*(int *)(param_1 + 0x18) != 0) {
        mali_sys_free();
      }
      mali_sys_lock_destroy(*(undefined4 *)(param_1 + 0x1c));
      mali_sys_free(param_1);
    }
    else {
      iVar1 = mali_image_deref();
      if (param_2 == 1) {
        while (iVar1 == 0) {
          iVar1 = mali_image_deref(*(undefined4 *)(param_1 + 0x20));
        }
      }
      if ((iVar1 != 1) && (*(int *)(*(int *)(param_1 + 0x20) + 0x10c) != 0)) {
        uVar2 = 1;
        FUN_4092af28(param_1,1);
        FUN_4092ae40(param_1,uVar2,param_3,param_4);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 4092b0c4 FUN_4092b0c4 */

/* Boundary evidence: original MIPS .pdata 4092b0c4..4092b177. Semantic name remains unreviewed. */

void FUN_4092b0c4(uint param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
  FUN_40935b30();
  iVar2 = param_3;
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x3008;
    }
  }
  else {
    iVar1 = FUN_4092b908(param_2);
    if (iVar1 == 0) {
      if (param_3 != 0) {
        *(undefined4 *)(param_3 + 0x10) = 0x300c;
      }
    }
    else if (*(uint *)(iVar1 + 8) == param_1) {
      *(undefined4 *)(iVar1 + 0x14) = 0;
      FUN_4092afc4(iVar1,0,iVar2,param_4,param_5,param_6);
    }
    else if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x3009;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 4092b178 FUN_4092b178 */

/* Boundary evidence: original MIPS .pdata 4092b178..4092b3cb. Semantic name remains unreviewed. */

void FUN_4092b178(uint param_1,uint param_2,uint param_3,int *param_4,int *param_5,int *param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  uint *puVar6;
  int *in_stack_00000048;
  int *in_stack_0000004c;
  
  FUN_40935a10();
  puVar6 = (uint *)0x0;
  piVar5 = param_4;
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (in_stack_0000004c != (int *)0x0) {
      in_stack_0000004c[4] = 0x3008;
    }
    goto LAB_4092b3c4;
  }
  iVar2 = FUN_4092bc34(param_2,param_1,(int)in_stack_0000004c);
  if (iVar2 == 0) goto LAB_4092b3c4;
  if (param_3 == 0x30b0) {
    param_5 = in_stack_0000004c;
    puVar6 = (uint *)FUN_40934934(iVar1,iVar2,param_4,in_stack_00000048,(int)in_stack_0000004c);
  }
  else if (param_3 == 0x30b1) {
    if ((*(uint *)(iVar2 + 0x28) & 2) == 0) goto LAB_4092b310;
    param_6 = in_stack_0000004c;
    param_5 = in_stack_00000048;
    piVar5 = param_4;
    puVar6 = (uint *)FUN_4093480c(iVar1,iVar2,0x30b1,param_4,in_stack_00000048,in_stack_0000004c);
    in_stack_00000048 = piVar5;
  }
  else if (param_3 < 0x30b3) {
LAB_4092b328:
    iVar1 = 0x300c;
LAB_4092b32c:
    if (in_stack_0000004c == (int *)0x0) goto LAB_4092b3c4;
    in_stack_0000004c[4] = iVar1;
    in_stack_00000048 = piVar5;
  }
  else if (param_3 < 0x30b9) {
    if ((*(uint *)(iVar2 + 0x28) & 4) == 0) {
LAB_4092b310:
      iVar1 = 0x30a1;
LAB_4092b314:
      if (*(int *)(iVar2 + 8) != iVar1) goto LAB_4092b328;
      iVar1 = 0x3009;
      goto LAB_4092b32c;
    }
    param_6 = in_stack_0000004c;
    param_5 = in_stack_00000048;
    piVar5 = param_4;
    puVar6 = (uint *)FUN_4093480c(iVar1,iVar2,param_3,param_4,in_stack_00000048,in_stack_0000004c);
    in_stack_00000048 = piVar5;
  }
  else {
    if (param_3 != 0x30b9) {
      if (param_3 == 0x30ba) {
        if ((*(uint *)(iVar2 + 0x28) & 1) != 0) {
          param_6 = in_stack_0000004c;
          param_5 = in_stack_00000048;
          piVar5 = param_4;
          puVar6 = (uint *)FUN_409346c4(iVar1,iVar2,0x30ba,(int)param_4,in_stack_00000048,
                                        in_stack_0000004c);
          in_stack_00000048 = piVar5;
          goto LAB_4092b358;
        }
        iVar1 = 0x30a0;
        goto LAB_4092b314;
      }
      goto LAB_4092b328;
    }
    if ((*(uint *)(iVar2 + 0x28) & 0x10) == 0) goto LAB_4092b310;
    param_6 = in_stack_0000004c;
    param_5 = in_stack_00000048;
    piVar5 = param_4;
    puVar6 = (uint *)FUN_4093480c(iVar1,iVar2,0x30b9,param_4,in_stack_00000048,in_stack_0000004c);
    in_stack_00000048 = piVar5;
  }
LAB_4092b358:
  if (puVar6 != (uint *)0x0) {
    puVar6[2] = param_1;
    puVar6[3] = param_2;
    *puVar6 = param_3;
    puVar6[1] = (uint)param_4;
    FUN_4092af28((int)puVar6,0);
    uVar4 = 5;
    uVar3 = FUN_4092c4e8((int)puVar6,0,5);
    if (((uVar3 == 0) || ((uVar3 | 0x10000000) == 0)) &&
       (FUN_4092afc4((int)puVar6,0,uVar4,in_stack_00000048,param_5,param_6),
       in_stack_0000004c != (int *)0x0)) {
      in_stack_0000004c[4] = 0x3003;
    }
  }
LAB_4092b3c4:
                    /* WARNING: Subroutine does not return */
  FUN_40935a40(0x18);
}



/* 4092b3cc FUN_4092b3cc */

/* Boundary evidence: original MIPS .pdata 4092b3cc..4092b46f. Semantic name remains unreviewed. */

undefined4 FUN_4092b3cc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = __mali_named_list_allocate();
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = __mali_named_list_allocate();
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  iVar2 = __mali_named_list_allocate();
  iVar3 = *(int *)(param_1 + 0x24);
  *(int *)(param_1 + 0x2c) = iVar2;
  if (iVar3 != 0) {
    if ((*(int *)(param_1 + 0x28) != 0) && (iVar2 != 0)) {
      return 1;
    }
    if (iVar3 != 0) {
      __mali_named_list_free(iVar3,0);
    }
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    __mali_named_list_free(*(int *)(param_1 + 0x28),0);
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    __mali_named_list_free(*(int *)(param_1 + 0x2c),0);
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return 0;
}



/* 4092b470 FUN_4092b470 */

/* Boundary evidence: original MIPS .pdata 4092b470..4092b4ab. Semantic name remains unreviewed. */

undefined4 FUN_4092b470(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x100) {
    uVar1 = *(undefined4 *)((param_2 + 7) * 4 + param_1);
  }
  else {
    uVar1 = __mali_named_list_get_non_flat();
  }
  return uVar1;
}



/* 4092b540 FUN_4092b540 */

/* Boundary evidence: original MIPS .pdata 4092b540..4092b5fb. Semantic name remains unreviewed. */

undefined4 FUN_4092b540(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  
  piVar1 = FUN_409319b8();
  iVar2 = __mali_named_list_iterate_begin(*piVar1,auStack_1c);
  do {
    if (iVar2 == 0) {
      return 0;
    }
    iVar3 = __mali_named_list_iterate_begin(*(undefined4 *)(iVar2 + 0x2c),auStack_20);
    while (iVar3 != 0) {
      if ((*(int *)(iVar3 + 0xc) == 1) && (param_1 == *(int *)(iVar3 + 200))) {
        return 1;
      }
      iVar3 = __mali_named_list_iterate_next(*(undefined4 *)(iVar2 + 0x2c),auStack_20);
    }
    iVar2 = __mali_named_list_iterate_next(*piVar1,auStack_1c);
  } while( true );
}



/* 4092b5fc FUN_4092b5fc */

/* Boundary evidence: original MIPS .pdata 4092b5fc..4092b697. Semantic name remains unreviewed. */

void FUN_4092b5fc(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  FUN_40935b30();
  piVar1 = FUN_409319b8();
  iVar2 = __mali_named_list_iterate_begin(*piVar1,&stack0x00000014);
  while (iVar2 != 0) {
    iVar3 = __mali_named_list_iterate_begin(*(undefined4 *)(iVar2 + 0x2c),&stack0x00000010);
    while (iVar3 != 0) {
      if ((*(int *)(iVar3 + 0xc) == 2) && (param_1 == *(int *)(iVar3 + 4))) goto LAB_4092b688;
      iVar3 = __mali_named_list_iterate_next(*(undefined4 *)(iVar2 + 0x2c),&stack0x00000010);
    }
    iVar2 = __mali_named_list_iterate_next(*piVar1,&stack0x00000014);
  }
LAB_4092b688:
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x18);
}



/* 4092b698 FUN_4092b698 */

/* Boundary evidence: original MIPS .pdata 4092b698..4092b733. Semantic name remains unreviewed. */

void FUN_4092b698(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  FUN_40935b30();
  piVar1 = FUN_409319b8();
  if (param_1 != 0) {
    iVar2 = __mali_named_list_iterate_begin(*piVar1,&stack0x00000014);
    while (iVar2 != 0) {
      piVar3 = (int *)__mali_named_list_iterate_begin
                                (*(undefined4 *)(iVar2 + 0x2c),&stack0x00000010);
      while (piVar3 != (int *)0x0) {
        if ((piVar3[3] == 0) && (param_1 == *piVar3)) goto LAB_4092b724;
        piVar3 = (int *)__mali_named_list_iterate_next
                                  (*(undefined4 *)(iVar2 + 0x2c),&stack0x00000010);
      }
      iVar2 = __mali_named_list_iterate_next(*piVar1,&stack0x00000014);
    }
  }
LAB_4092b724:
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x18);
}



/* 4092b734 FUN_4092b734 */

/* Boundary evidence: original MIPS .pdata 4092b734..4092b75b. Semantic name remains unreviewed. */

void FUN_4092b734(void)

{
  int *piVar1;
  undefined1 auStack_10 [8];
  
  piVar1 = FUN_409319b8();
  __mali_named_list_iterate_begin(*piVar1,auStack_10);
  return;
}



/* 4092b75c FUN_4092b75c */

/* Boundary evidence: original MIPS .pdata 4092b75c..4092b7cb. Semantic name remains unreviewed. */

undefined4 FUN_4092b75c(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_18 [2];
  
  piVar1 = FUN_409319b8();
  piVar2 = (int *)__mali_named_list_iterate_begin(*piVar1,local_18);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    if (param_1 == *piVar2) break;
    piVar2 = (int *)__mali_named_list_iterate_next(*piVar1,local_18);
  }
  return local_18[0];
}



/* 4092b7cc FUN_4092b7cc */

/* Boundary evidence: original MIPS .pdata 4092b7cc..4092b907. Semantic name remains unreviewed. */

void FUN_4092b7cc(uint param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  FUN_40935ae0();
  piVar1 = FUN_409319b8();
  if (param_3 == 1) {
    if ((param_1 & 0x70000000) != 0) goto LAB_4092b900;
  }
  else {
    if ((param_2 & 0x70000000) != 0) goto LAB_4092b900;
    uVar3 = (param_2 ^ 0x70000000) & param_2;
    if (uVar3 < 0x100) {
      iVar2 = *(int *)((uVar3 + 7) * 4 + *piVar1);
    }
    else {
      iVar2 = __mali_named_list_get_non_flat();
    }
    if (param_3 == 2) {
      if (iVar2 == 0) goto LAB_4092b900;
      uVar3 = 0x20000000;
    }
    else if (param_3 == 3) {
      if (iVar2 == 0) goto LAB_4092b900;
      uVar3 = 0x40000000;
    }
    else if (param_3 == 4) {
      if (iVar2 == 0) goto LAB_4092b900;
      uVar3 = 0x60000000;
    }
    else {
      if (param_3 != 5) goto LAB_4092b900;
      uVar3 = 0x10000000;
    }
    if ((param_1 & 0x70000000) != uVar3) goto LAB_4092b900;
  }
  if (0xff < ((param_1 ^ 0x70000000) & param_1)) {
    __mali_named_list_get_non_flat();
  }
LAB_4092b900:
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x10);
}



/* 4092b908 FUN_4092b908 */

/* Boundary evidence: original MIPS .pdata 4092b908..4092b977. Semantic name remains unreviewed. */

undefined4 FUN_4092b908(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  
  piVar1 = FUN_409319b8();
  if ((param_1 & 0x70000000) == 0x10000000) {
    uVar3 = (param_1 ^ 0x70000000) & param_1;
    if (uVar3 < 0x100) {
      uVar2 = *(undefined4 *)((uVar3 + 7) * 4 + piVar1[0x12]);
    }
    else {
      uVar2 = __mali_named_list_get_non_flat();
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4092b978 FUN_4092b978 */

/* Boundary evidence: original MIPS .pdata 4092b978..4092ba27. Semantic name remains unreviewed. */

void FUN_4092b978(uint param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  FUN_40935b30();
  piVar1 = FUN_409319b8();
  if ((param_2 & 0x70000000) == 0) {
    uVar3 = (param_2 ^ 0x70000000) & param_2;
    if (uVar3 < 0x100) {
      iVar2 = *(int *)((uVar3 + 7) * 4 + *piVar1);
    }
    else {
      iVar2 = __mali_named_list_get_non_flat();
    }
    if (((iVar2 != 0) && ((param_1 & 0x70000000) == 0x40000000)) &&
       (0xff < ((param_1 ^ 0x70000000) & param_1))) {
      __mali_named_list_get_non_flat();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 4092ba28 FUN_4092ba28 */

/* Boundary evidence: original MIPS .pdata 4092ba28..4092bad7. Semantic name remains unreviewed. */

void FUN_4092ba28(uint param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  FUN_40935b30();
  piVar1 = FUN_409319b8();
  if ((param_2 & 0x70000000) == 0) {
    uVar3 = (param_2 ^ 0x70000000) & param_2;
    if (uVar3 < 0x100) {
      iVar2 = *(int *)((uVar3 + 7) * 4 + *piVar1);
    }
    else {
      iVar2 = __mali_named_list_get_non_flat();
    }
    if (((iVar2 != 0) && ((param_1 & 0x70000000) == 0x20000000)) &&
       (0xff < ((param_1 ^ 0x70000000) & param_1))) {
      __mali_named_list_get_non_flat();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 4092bad8 FUN_4092bad8 */

/* Boundary evidence: original MIPS .pdata 4092bad8..4092bb87. Semantic name remains unreviewed. */

void FUN_4092bad8(uint param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  FUN_40935b30();
  piVar1 = FUN_409319b8();
  if ((param_2 & 0x70000000) == 0) {
    uVar3 = (param_2 ^ 0x70000000) & param_2;
    if (uVar3 < 0x100) {
      iVar2 = *(int *)((uVar3 + 7) * 4 + *piVar1);
    }
    else {
      iVar2 = __mali_named_list_get_non_flat();
    }
    if (((iVar2 != 0) && ((param_1 & 0x70000000) == 0x60000000)) &&
       (0xff < ((param_1 ^ 0x70000000) & param_1))) {
      __mali_named_list_get_non_flat();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 4092bb88 FUN_4092bb88 */

/* Boundary evidence: original MIPS .pdata 4092bb88..4092bbf3. Semantic name remains unreviewed. */

undefined4 FUN_4092bb88(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  
  piVar1 = FUN_409319b8();
  if ((param_1 & 0x70000000) == 0) {
    uVar3 = (param_1 ^ 0x70000000) & param_1;
    if (uVar3 < 0x100) {
      uVar2 = *(undefined4 *)((uVar3 + 7) * 4 + *piVar1);
    }
    else {
      uVar2 = __mali_named_list_get_non_flat();
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4092bbf4 FUN_4092bbf4 */

/* Boundary evidence: original MIPS .pdata 4092bbf4..4092bc33. Semantic name remains unreviewed. */

int FUN_4092bbf4(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_4092b908(param_1);
  if (iVar1 == 0) {
    if (param_2 != 0) {
      *(undefined4 *)(param_2 + 0x10) = 0x300c;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4092bc34 FUN_4092bc34 */

/* Boundary evidence: original MIPS .pdata 4092bc34..4092bc83. Semantic name remains unreviewed. */

int FUN_4092bc34(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_4092b978(param_1,param_2);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x24) != 1)) {
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x3006;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4092bc84 FUN_4092bc84 */

/* Boundary evidence: original MIPS .pdata 4092bc84..4092bcd3. Semantic name remains unreviewed. */

int FUN_4092bc84(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_4092ba28(param_1,param_2);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0xa8) != 1)) {
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x300d;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4092bcd4 FUN_4092bcd4 */

/* Boundary evidence: original MIPS .pdata 4092bcd4..4092bd13. Semantic name remains unreviewed. */

int FUN_4092bcd4(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_4092bad8(param_1,param_2);
  if (iVar1 == 0) {
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x3005;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4092bd14 FUN_4092bd14 */

/* Boundary evidence: original MIPS .pdata 4092bd14..4092bd53. Semantic name remains unreviewed. */

int FUN_4092bd14(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_2 != 0) {
      *(undefined4 *)(param_2 + 0x10) = 0x3008;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4092bd54 FUN_4092bd54 */

/* Boundary evidence: original MIPS .pdata 4092bd54..4092be93. Semantic name remains unreviewed. */

void FUN_4092bd54(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  FUN_40935ae0();
  piVar1 = FUN_409319b8();
  if (param_3 == 1) {
    iVar3 = *piVar1;
  }
  else if (param_3 == 2) {
    iVar3 = FUN_4092bb88(param_2);
    iVar3 = *(int *)(iVar3 + 0x2c);
  }
  else if (param_3 == 3) {
    iVar3 = FUN_4092bb88(param_2);
    iVar3 = *(int *)(iVar3 + 0x28);
  }
  else {
    if (param_3 != 5) goto LAB_4092be04;
    iVar3 = piVar1[0x12];
  }
  iVar2 = __mali_named_list_iterate_begin(iVar3,&param_6);
  while (iVar2 != 0) {
    if (param_1 == iVar2) {
      if (param_3 == 1) {
        iVar3 = *(int *)(iVar2 + 0x24);
        if (iVar3 != 0) {
          while( true ) {
            iVar3 = __mali_named_list_iterate_begin(iVar3,&param_5);
            if (iVar3 == 0) break;
            __mali_named_list_remove(*(undefined4 *)(iVar2 + 0x24),param_5);
            iVar3 = *(int *)(iVar2 + 0x24);
          }
          __mali_named_list_free(*(undefined4 *)(iVar2 + 0x24),0);
        }
        if (*(int *)(iVar2 + 0x28) != 0) {
          __mali_named_list_free(*(int *)(iVar2 + 0x28),0);
        }
        if (*(int *)(iVar2 + 0x2c) != 0) {
          __mali_named_list_free(*(int *)(iVar2 + 0x2c),0);
        }
      }
      else {
        __mali_named_list_remove(iVar3,param_6);
      }
      break;
    }
    iVar2 = __mali_named_list_iterate_next(iVar3,&param_6);
  }
LAB_4092be04:
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 4092be94 FUN_4092be94 */

/* Boundary evidence: original MIPS .pdata 4092be94..4092bf17. Semantic name remains unreviewed. */

uint FUN_4092be94(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint local_18 [2];
  
  iVar1 = FUN_4092bb88(param_2);
  if (iVar1 != 0) {
    iVar2 = __mali_named_list_iterate_begin(*(undefined4 *)(iVar1 + 0x24),local_18);
    while (iVar2 != 0) {
      if (param_1 == *(int *)(iVar2 + 0x2c)) {
        return local_18[0] | 0x60000000;
      }
      iVar2 = __mali_named_list_iterate_next(*(undefined4 *)(iVar1 + 0x24),local_18);
    }
  }
  return 0;
}



/* 4092bf18 FUN_4092bf18 */

/* Boundary evidence: original MIPS .pdata 4092bf18..4092bfc7. Semantic name remains unreviewed. */

int FUN_4092bf18(uint *param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_20 [2];
  
  iVar3 = 0;
  iVar1 = FUN_4092bb88(param_2);
  if (iVar1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar2 = __mali_named_list_iterate_begin(*(undefined4 *)(iVar1 + 0x24),local_20);
    if (0 < param_3) {
      do {
        if (iVar2 == 0) {
          return iVar3;
        }
        *param_1 = local_20[0] | 0x60000000;
        iVar3 = iVar3 + 1;
        iVar2 = __mali_named_list_iterate_next(*(undefined4 *)(iVar1 + 0x24),local_20);
        param_1 = param_1 + 1;
      } while (iVar3 < param_3);
    }
  }
  return iVar3;
}



/* 4092bfc8 FUN_4092bfc8 */

/* Boundary evidence: original MIPS .pdata 4092bfc8..4092c0cf. Semantic name remains unreviewed. */

undefined4 FUN_4092bfc8(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20 [2];
  
  piVar1 = FUN_409319b8();
  if (param_1 == 0) {
    return 0;
  }
  iVar2 = FUN_4092bb88(param_2);
  if (param_3 == 1) {
    iVar2 = *piVar1;
  }
  else if (param_3 == 2) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = *(int *)(iVar2 + 0x2c);
  }
  else if (param_3 == 3) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = *(int *)(iVar2 + 0x28);
  }
  else if (param_3 == 4) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = *(int *)(iVar2 + 0x24);
  }
  else {
    if (param_3 != 5) {
      return 0;
    }
    iVar2 = piVar1[0x12];
  }
  iVar3 = __mali_named_list_iterate_begin(iVar2,local_20);
  while( true ) {
    if (iVar3 == 0) {
      return 0;
    }
    if (param_1 == iVar3) break;
    iVar3 = __mali_named_list_iterate_next(iVar2,local_20);
  }
  return local_20[0];
}



/* 4092c0d0 FUN_4092c0d0 */

/* Boundary evidence: original MIPS .pdata 4092c0d0..4092c0ef. Semantic name remains unreviewed. */

void FUN_4092c0d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  FUN_4092bd54(param_1,0,5,param_4,unaff_retaddr,in_stack_fffffffc);
  return;
}



/* 4092c0f0 FUN_4092c0f0 */

/* Boundary evidence: original MIPS .pdata 4092c0f0..4092c10b. Semantic name remains unreviewed. */

void FUN_4092c0f0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  FUN_4092bd54(param_1,param_2,3,param_4,unaff_retaddr,in_stack_fffffffc);
  return;
}



/* 4092c10c FUN_4092c10c */

/* Boundary evidence: original MIPS .pdata 4092c10c..4092c127. Semantic name remains unreviewed. */

void FUN_4092c10c(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  FUN_4092bd54(param_1,param_2,2,param_4,unaff_retaddr,in_stack_fffffffc);
  return;
}



/* 4092c128 FUN_4092c128 */

/* Boundary evidence: original MIPS .pdata 4092c128..4092c1d3. Semantic name remains unreviewed. */

undefined4 FUN_4092c128(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  piVar1 = FUN_409319b8();
  iVar2 = FUN_4092bd54(param_1,0,1,param_4,in_stack_ffffffe0,in_stack_ffffffe4);
  if ((iVar2 == 1) && (param_2 == 1)) {
    iVar2 = __mali_named_list_iterate_begin(*piVar1,&stack0xffffffe0);
    while (iVar2 != 0) {
      if (param_1 == iVar2) {
        __mali_named_list_remove(*piVar1,in_stack_ffffffe0);
        return 1;
      }
      iVar2 = __mali_named_list_iterate_next(*piVar1,&stack0xffffffe0);
    }
  }
  return 0;
}



/* 4092c1d4 FUN_4092c1d4 */

/* Boundary evidence: original MIPS .pdata 4092c1d4..4092c20b. Semantic name remains unreviewed. */

uint FUN_4092c1d4(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_4092bfc8(param_1,0,5);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x10000000;
  }
  return uVar1;
}



/* 4092c20c FUN_4092c20c */

/* Boundary evidence: original MIPS .pdata 4092c20c..4092c23f. Semantic name remains unreviewed. */

uint FUN_4092c20c(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_4092bfc8(param_1,param_2,3);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x40000000;
  }
  return uVar1;
}



/* 4092c240 FUN_4092c240 */

/* Boundary evidence: original MIPS .pdata 4092c240..4092c273. Semantic name remains unreviewed. */

uint FUN_4092c240(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_4092bfc8(param_1,param_2,2);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x20000000;
  }
  return uVar1;
}



/* 4092c274 FUN_4092c274 */

/* Boundary evidence: original MIPS .pdata 4092c274..4092c2a7. Semantic name remains unreviewed. */

uint FUN_4092c274(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_4092bfc8(param_1,param_2,4);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x60000000;
  }
  return uVar1;
}



/* 4092c2a8 FUN_4092c2a8 */

/* Boundary evidence: original MIPS .pdata 4092c2a8..4092c2c7. Semantic name remains unreviewed. */

void FUN_4092c2a8(int param_1)

{
  FUN_4092bfc8(param_1,0,1);
  return;
}



/* 4092c2c8 FUN_4092c2c8 */

/* Boundary evidence: original MIPS .pdata 4092c2c8..4092c3c3. Semantic name remains unreviewed. */

void FUN_4092c2c8(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5
                 ,uint param_6)

{
  int iVar1;
  int iVar2;
  
  FUN_40935b30();
  param_5 = 0;
  param_6 = 0;
  iVar1 = FUN_4092bb88(param_1);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x28) != 0)) &&
     (iVar2 = __mali_named_list_size(), iVar2 != 0)) {
    iVar2 = __mali_named_list_iterate_begin(*(undefined4 *)(iVar1 + 0x28),&param_5);
    while (iVar2 != 0) {
      FUN_409325c8(param_1,iVar2,1,param_4);
      if (param_5 < 0x100) {
        iVar2 = *(int *)((param_5 + 7) * 4 + *(int *)(iVar1 + 0x28));
      }
      else {
        iVar2 = __mali_named_list_get_non_flat(*(int *)(iVar1 + 0x28),param_5);
      }
      if (iVar2 == 0) {
        if (param_6 == 0) {
          iVar2 = __mali_named_list_iterate_begin(*(undefined4 *)(iVar1 + 0x28),&param_5);
        }
        else {
          iVar2 = __mali_named_list_iterate_next(*(undefined4 *)(iVar1 + 0x28),&param_6);
        }
      }
      else {
        param_6 = param_5;
        iVar2 = __mali_named_list_iterate_next(*(undefined4 *)(iVar1 + 0x28),&param_5);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x18);
}



/* 4092c3c4 FUN_4092c3c4 */

/* Boundary evidence: original MIPS .pdata 4092c3c4..4092c4e7. Semantic name remains unreviewed. */

undefined4 FUN_4092c3c4(uint param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint local_20;
  uint local_1c;
  
  local_20 = 0;
  local_1c = 0;
  uVar4 = 1;
  iVar1 = FUN_4092bb88(param_1);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x2c) != 0)) &&
     (iVar2 = __mali_named_list_size(), iVar2 != 0)) {
    puVar3 = (undefined4 *)__mali_named_list_iterate_begin(*(undefined4 *)(iVar1 + 0x2c),&local_20);
    while (puVar3 != (undefined4 *)0x0) {
      FUN_4092d908(param_1,puVar3,1,param_2);
      if (local_20 < 0x100) {
        iVar2 = *(int *)((local_20 + 7) * 4 + *(int *)(iVar1 + 0x2c));
      }
      else {
        iVar2 = __mali_named_list_get_non_flat(*(int *)(iVar1 + 0x2c),local_20);
      }
      if (iVar2 == 0) {
        if (local_1c == 0) {
          puVar3 = (undefined4 *)
                   __mali_named_list_iterate_begin(*(undefined4 *)(iVar1 + 0x2c),&local_20);
        }
        else {
          puVar3 = (undefined4 *)
                   __mali_named_list_iterate_next(*(undefined4 *)(iVar1 + 0x2c),&local_1c);
        }
      }
      else {
        local_1c = local_20;
        puVar3 = (undefined4 *)
                 __mali_named_list_iterate_next(*(undefined4 *)(iVar1 + 0x2c),&local_20);
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}



/* 4092c4e8 FUN_4092c4e8 */

/* Boundary evidence: original MIPS .pdata 4092c4e8..4092c65f. Semantic name remains unreviewed. */

void FUN_4092c4e8(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  FUN_40935ae0();
  piVar1 = FUN_409319b8();
  iVar2 = FUN_4092bb88(param_2);
  if (param_3 == 1) {
    iVar2 = FUN_4092bfc8(param_1,0,1);
    if (iVar2 != 0) goto LAB_4092c654;
    iVar2 = *piVar1;
  }
  else if (param_3 == 2) {
    uVar3 = FUN_4092bfc8(param_1,param_2,2);
    if ((uVar3 != 0) && ((uVar3 | 0x20000000) != 0)) goto LAB_4092c654;
    iVar2 = *(int *)(iVar2 + 0x2c);
  }
  else if (param_3 == 3) {
    uVar3 = FUN_4092bfc8(param_1,param_2,3);
    if ((uVar3 != 0) && ((uVar3 | 0x40000000) != 0)) goto LAB_4092c654;
    iVar2 = *(int *)(iVar2 + 0x28);
  }
  else if (param_3 == 4) {
    uVar3 = FUN_4092bfc8(param_1,param_2,4);
    if ((uVar3 != 0) && ((uVar3 | 0x60000000) != 0)) goto LAB_4092c654;
    iVar2 = *(int *)(iVar2 + 0x24);
  }
  else {
    if ((param_3 != 5) ||
       ((uVar3 = FUN_4092bfc8(param_1,0,5), uVar3 != 0 && ((uVar3 | 0x10000000) != 0))))
    goto LAB_4092c654;
    iVar2 = piVar1[0x12];
  }
  uVar4 = __mali_named_list_get_unused_name(iVar2);
  __mali_named_list_insert(iVar2,uVar4,param_1);
LAB_4092c654:
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x10);
}



/* 4092c660 FUN_4092c660 */

/* Boundary evidence: original MIPS .pdata 4092c660..4092c697. Semantic name remains unreviewed. */

uint FUN_4092c660(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_4092c4e8(param_1,0,5);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x10000000;
  }
  return uVar1;
}



/* 4092c698 FUN_4092c698 */

/* Boundary evidence: original MIPS .pdata 4092c698..4092c6cb. Semantic name remains unreviewed. */

uint FUN_4092c698(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_4092c4e8(param_1,param_2,3);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x40000000;
  }
  return uVar1;
}



/* 4092c6cc FUN_4092c6cc */

/* Boundary evidence: original MIPS .pdata 4092c6cc..4092c6ff. Semantic name remains unreviewed. */

uint FUN_4092c6cc(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_4092c4e8(param_1,param_2,2);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x20000000;
  }
  return uVar1;
}



/* 4092c700 FUN_4092c700 */

/* Boundary evidence: original MIPS .pdata 4092c700..4092c733. Semantic name remains unreviewed. */

uint FUN_4092c700(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_4092c4e8(param_1,param_2,4);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x60000000;
  }
  return uVar1;
}



/* 4092c734 FUN_4092c734 */

/* Boundary evidence: original MIPS .pdata 4092c734..4092c753. Semantic name remains unreviewed. */

void FUN_4092c734(int param_1)

{
  FUN_4092c4e8(param_1,0,1);
  return;
}



/* 4092c754 FUN_4092c754 */

/* Boundary evidence: original MIPS .pdata 4092c754..4092c807. Semantic name remains unreviewed. */

void FUN_4092c754(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  iVar3 = param_3;
  if (param_1 == 0) {
    return;
  }
  do {
    iVar1 = __mali_named_list_iterate_begin(param_1,&stack0xffffffe0);
    while( true ) {
      if (iVar1 == 0) {
        return;
      }
      if (((param_2 == *(int *)(iVar1 + 8)) || (param_2 == 0)) &&
         (iVar2 = FUN_4092afc4(iVar1,param_3,iVar3,param_4,in_stack_ffffffe0,in_stack_ffffffe4),
         iVar2 == 1)) break;
      iVar1 = __mali_named_list_iterate_next(param_1,&stack0xffffffe0);
    }
    iVar3 = 5;
    FUN_4092bd54(iVar1,0,5,param_4,in_stack_ffffffe0,in_stack_ffffffe4);
  } while( true );
}



/* 4092c808 FUN_4092c808 */

undefined4 FUN_4092c808(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x30a0;
  if (param_1[3] == 0x30a0) {
    uVar1 = param_1[1];
  }
  else {
    uVar2 = 0x30a1;
    if (param_1[3] != 0x30a1) {
      uVar1 = 0;
      if (param_2 == (undefined4 *)0x0) {
        return 0;
      }
      uVar2 = 0x3038;
      goto LAB_4092c848;
    }
    uVar1 = *param_1;
  }
  if (param_2 == (undefined4 *)0x0) {
    return uVar1;
  }
LAB_4092c848:
  *param_2 = uVar2;
  return uVar1;
}



/* 4092c854 FUN_4092c854 */

/* Boundary evidence: original MIPS .pdata 4092c854..4092c88f. Semantic name remains unreviewed. */

undefined4 FUN_4092c854(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x100) {
    uVar1 = *(undefined4 *)((param_2 + 7) * 4 + param_1);
  }
  else {
    uVar1 = __mali_named_list_get_non_flat();
  }
  return uVar1;
}



/* 4092c890 FUN_4092c890 */

/* Boundary evidence: original MIPS .pdata 4092c890..4092c8ab. Semantic name remains unreviewed. */

void FUN_4092c890(void)

{
  FUN_40931c10(1);
  return;
}



/* 4092c8ac FUN_4092c8ac */

/* Boundary evidence: original MIPS .pdata 4092c8ac..4092c9af. Semantic name remains unreviewed. */

undefined4 FUN_4092c8ac(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int in_stack_ffffffec;
  
  puVar1 = (undefined4 *)mali_sys_thread_key_get_data(0);
  if (puVar1 != (undefined4 *)0x0) {
    iVar3 = puVar1[2];
    if ((int *)puVar1[1] != (int *)0x0) {
      uVar2 = FUN_4092bfc8(*(int *)puVar1[1],0,1);
      puVar1[3] = 0x30a0;
      FUN_409329a4(uVar2,0,(int *)0x0,0,puVar1,in_stack_ffffffec);
      mali_sys_free(puVar1[1]);
      puVar1[1] = 0;
      puVar1[7] = 0;
    }
    if ((int *)*puVar1 != (int *)0x0) {
      uVar2 = FUN_4092bfc8(*(int *)*puVar1,0,1);
      puVar1[3] = 0x30a1;
      FUN_409329a4(uVar2,0,(int *)0x0,0,puVar1,in_stack_ffffffec);
      mali_sys_free(*puVar1);
      *puVar1 = 0;
      puVar1[6] = 0;
    }
    __mali_named_list_lock(*(undefined4 *)(iVar3 + 8));
    mali_sys_thread_key_set_data(0,0);
    __mali_named_list_remove(*(undefined4 *)(iVar3 + 8),puVar1[5]);
    mali_sys_free(puVar1);
    __mali_named_list_unlock(*(undefined4 *)(iVar3 + 8));
  }
  return 1;
}



/* 4092c9b0 FUN_4092c9b0 */

/* Boundary evidence: original MIPS .pdata 4092c9b0..4092cbf7. Semantic name remains unreviewed. */

void FUN_4092c9b0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int in_stack_00000014;
  
  FUN_40935ae0();
  iVar1 = mali_sys_thread_key_get_data(0);
  if (iVar1 == 0) {
    piVar2 = FUN_409319b8();
    if ((piVar2 == (int *)0x0) ||
       (puVar3 = (undefined4 *)mali_sys_calloc(1,0x20), puVar3 == (undefined4 *)0x0))
    goto LAB_4092cbec;
    puVar3[3] = 0x30a0;
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[4] = 0x3000;
    puVar3[2] = piVar2;
    uVar4 = mali_sys_thread_get_current();
    puVar3[5] = uVar4;
    puVar3[6] = 0;
    puVar3[7] = 0;
    __mali_named_list_lock(piVar2[2]);
    iVar1 = __mali_named_list_insert(piVar2[2],puVar3[5],puVar3);
    if (iVar1 == -2) {
      if ((uint)puVar3[5] < 0x100) {
        piVar7 = *(int **)((puVar3[5] + 7) * 4 + piVar2[2]);
      }
      else {
        piVar7 = (int *)__mali_named_list_get_non_flat();
      }
      if (piVar7 != (int *)0x0) {
        if ((int *)piVar7[1] != (int *)0x0) {
          uVar5 = FUN_4092bfc8(*(int *)piVar7[1],0,1);
          iVar1 = FUN_40932150(0x30a0,piVar7);
          iVar6 = piVar7[1];
          if ((((*(int *)(iVar6 + 0xc) != 0) || (*(int *)(iVar6 + 4) != 0)) ||
              (*(int *)(iVar6 + 8) != 0)) && (iVar1 == 1)) {
            FUN_409329a4(uVar5,0,(int *)0x0,0,piVar7,in_stack_00000014);
          }
          mali_sys_free(piVar7[1]);
          piVar7[1] = 0;
        }
        if ((int *)*piVar7 != (int *)0x0) {
          uVar5 = FUN_4092bfc8(*(int *)*piVar7,0,1);
          iVar1 = FUN_40932150(0x30a1,piVar7);
          iVar6 = *piVar7;
          if ((((*(int *)(iVar6 + 0xc) != 0) || (*(int *)(iVar6 + 4) != 0)) ||
              (*(int *)(iVar6 + 8) != 0)) && (iVar1 == 1)) {
            FUN_409329a4(uVar5,0,(int *)0x0,0,piVar7,in_stack_00000014);
          }
          mali_sys_free(*piVar7);
          *piVar7 = 0;
        }
        mali_sys_free(piVar7);
      }
      iVar1 = __mali_named_list_set(piVar2[2],puVar3[5],puVar3);
    }
    __mali_named_list_unlock(piVar2[2]);
    if ((iVar1 != 0) || (iVar1 = mali_sys_thread_key_set_data(0,puVar3), iVar1 != 0)) {
      mali_sys_free(puVar3);
      goto LAB_4092cbec;
    }
  }
  FUN_40931c10(0);
LAB_4092cbec:
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 4092cbf8 FUN_4092cbf8 */

void FUN_4092cbf8(int param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  *(undefined4 *)(param_1 + 0xcc) = 0x3089;
  *(undefined4 *)(param_1 + 0xc4) = 0x308b;
  *(int *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0xb8) = param_2;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (param_4 == 2) {
    *(undefined4 *)(param_1 + 0xe4) = 0x3085;
    *(undefined4 *)(param_1 + 4) = *param_3;
  }
  else {
    *(undefined4 *)(param_1 + 0xe4) = 0x3084;
  }
  *(undefined4 *)(param_1 + 0xf0) = 0x305c;
  *(undefined4 *)(param_1 + 0xf4) = 0x305c;
  *(undefined4 *)(param_1 + 0xe8) = 0x3095;
  *(undefined4 *)(param_1 + 0xec) = 0x309a;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xd0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xf8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 1;
  *(undefined2 *)(param_1 + 0x70) = 0;
  *(undefined2 *)(param_1 + 0x72) = 1;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  return;
}



/* 4092cca8 FUN_4092cca8 */

/* Boundary evidence: original MIPS .pdata 4092cca8..4092cd17. Semantic name remains unreviewed. */

int FUN_4092cca8(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x34);
  if (iVar1 == 0) {
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      if (*(int *)(param_1 + 0x48) == 0) {
        *(int *)(param_1 + 0x48) = param_1;
      }
      (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x44))
      ;
    }
    mali_surface_free(param_1);
  }
  return iVar1;
}



/* 4092cd18 FUN_4092cd18 */

/* Boundary evidence: original MIPS .pdata 4092cd18..4092d00f. Semantic name remains unreviewed. */

void FUN_4092cd18(int param_1,int *param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint *in_stack_00000020;
  uint *in_stack_00000024;
  int in_stack_00000028;
  
  FUN_40935b30();
  if (in_stack_00000028 == 1) {
    *in_stack_00000020 = 0;
    *in_stack_00000024 = 0;
  }
  if (param_2 == (int *)0x0) {
LAB_4092d008:
                    /* WARNING: Subroutine does not return */
    FUN_40935b50(0);
  }
  bVar1 = false;
LAB_4092cd60:
  iVar4 = *param_2;
  if (iVar4 < 0x3082) {
    if (iVar4 == 0x3081) {
      if (param_2[1] != 0x305c) {
        if ((((*(uint *)(param_3 + 0x5c) & 1) == 0) && ((*(uint *)(param_3 + 0x5c) & 4) == 0)) ||
           (param_2[1] != 0x305f)) goto LAB_4092cff4;
        *(undefined4 *)(param_4 + 0xf4) = 0x305f;
      }
LAB_4092cfd0:
      prefetch(param_2 + 4,0);
      param_2 = param_2 + 2;
      if (bVar1) goto LAB_4092d008;
      goto LAB_4092cd60;
    }
    if (iVar4 == 0x3038) {
      bVar1 = true;
      goto LAB_4092cfd0;
    }
    if (iVar4 == 0x3056) {
      if (in_stack_00000028 != 1) goto LAB_4092cff4;
      uVar5 = param_2[1];
      if ((-1 < (int)uVar5) && (uVar5 < 0x1001)) {
        *in_stack_00000024 = uVar5;
        *(uint *)(param_4 + 0xc0) = uVar5;
        goto LAB_4092cfd0;
      }
LAB_4092cfe4:
      if (param_1 == 0) goto LAB_4092d008;
      uVar3 = 0x300c;
      goto LAB_4092d000;
    }
    if (iVar4 == 0x3057) {
      if (in_stack_00000028 == 1) {
        uVar5 = param_2[1];
        if (((int)uVar5 < 0) || (0x1000 < uVar5)) goto LAB_4092cfe4;
        *in_stack_00000020 = uVar5;
        *(uint *)(param_4 + 0xbc) = uVar5;
        goto LAB_4092cfd0;
      }
    }
    else if (iVar4 == 0x3058) {
      iVar4 = param_2[1];
      if ((iVar4 == 0) || (iVar4 == 1)) {
        *(int *)(param_4 + 0xd4) = iVar4;
        goto LAB_4092cfd0;
      }
    }
    else if (iVar4 == 0x3080) {
      iVar4 = param_2[1];
      if (iVar4 == 0x305c) goto LAB_4092cfd0;
      if (((*(uint *)(param_3 + 0x5c) & 1) != 0) || ((*(uint *)(param_3 + 0x5c) & 4) != 0)) {
        if (iVar4 == 0x305d) {
          iVar2 = *(int *)(param_3 + 0x1c);
        }
        else {
          if (iVar4 != 0x305e) goto LAB_4092cff4;
          iVar2 = *(int *)(param_3 + 0x20);
        }
        if (iVar2 == 0) goto LAB_4092ce04;
        *(int *)(param_4 + 0xf0) = iVar4;
        goto LAB_4092cfd0;
      }
    }
  }
  else if (iVar4 == 0x3082) {
    if ((((*(uint *)(param_3 + 0x5c) & 1) != 0) || ((*(uint *)(param_3 + 0x5c) & 4) != 0)) &&
       ((iVar4 = param_2[1], iVar4 == 0 || (iVar4 == 1)))) {
      *(int *)(param_4 + 0xd8) = iVar4;
      goto LAB_4092cfd0;
    }
  }
  else if (iVar4 == 0x3086) {
    if ((param_2[1] == 0x3084) || (param_2[1] == 0x3085)) {
      *(undefined4 *)(param_4 + 0xe4) = 0x3084;
      goto LAB_4092cfd0;
    }
  }
  else {
    if (iVar4 != 0x3087) {
      if ((iVar4 != 0x3088) || ((iVar4 = param_2[1], iVar4 != 0x308b && (iVar4 != 0x308c))))
      goto LAB_4092cff4;
      if ((iVar4 != 0x308c) || ((*(uint *)(param_3 + 0x6c) & 0x40) != 0)) {
        *(int *)(param_4 + 0xc4) = iVar4;
        goto LAB_4092cfd0;
      }
LAB_4092ce04:
      if (param_1 != 0) {
        uVar3 = 0x3009;
        goto LAB_4092d000;
      }
      goto LAB_4092d008;
    }
    iVar4 = param_2[1];
    if ((iVar4 == 0x3089) || (iVar4 == 0x308a)) {
      if ((iVar4 == 0x308a) && ((*(uint *)(param_3 + 0x6c) & 0x20) == 0)) goto LAB_4092ce04;
      *(int *)(param_4 + 0xcc) = iVar4;
      goto LAB_4092cfd0;
    }
  }
LAB_4092cff4:
  if (param_1 == 0) goto LAB_4092d008;
  uVar3 = 0x3004;
LAB_4092d000:
  *(undefined4 *)(param_1 + 0x10) = uVar3;
  goto LAB_4092d008;
}



/* 4092d010 FUN_4092d010 */

/* Boundary evidence: original MIPS .pdata 4092d010..4092d097. Semantic name remains unreviewed. */

void FUN_4092d010(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_40935b30();
  if ((param_1[4] & 2) != 0) {
    iVar1 = mali_render_attachment_get_target(param_1[0x1a],0,0);
    iVar2 = mali_render_attachment_get_target(param_1[0x1a],1,0);
    mali_render_attachment_free(param_1[0x1a]);
    if (iVar1 != 0) {
      FUN_4092cca8(iVar1);
    }
    if ((iVar2 != 0) && (iVar1 != iVar2)) {
      FUN_4092cca8(iVar2);
    }
  }
  FUN_40929564(param_1);
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 4092d098 FUN_4092d098 */

/* Boundary evidence: original MIPS .pdata 4092d098..4092d1bf. Semantic name remains unreviewed. */

void FUN_4092d098(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  FUN_40935b30();
  if (param_1[0x27] == 0) {
    if ((param_2 != (int *)0x0) && (param_1[0x32] != 0)) {
      FUN_40927140((int)param_1,param_2);
    }
    while ((param_1[7] == 1 || (param_1[0xc] == 1))) {
      mali_sys_yield();
    }
    piVar2 = param_1 + 9;
    iVar3 = 4;
    do {
      if (*piVar2 != 0) {
        mali_ds_consumer_release_connections(*piVar2,0,0,0x7fffffff);
        *piVar2 = 0;
      }
      iVar3 = iVar3 + -1;
      piVar2 = piVar2 + 5;
    } while (iVar3 != 0);
    if (((param_1[4] & 2) != 0) && (param_1[0x1a] != 0)) {
      iVar3 = mali_render_attachment_get_target(param_1[0x1a],0,0);
      iVar1 = mali_render_attachment_get_target(param_1[0x1a],1,0);
      mali_render_attachment_free(param_1[0x1a]);
      if (iVar3 != 0) {
        FUN_4092cca8(iVar3);
      }
      if ((iVar1 != 0) && (iVar3 != iVar1)) {
        FUN_4092cca8(iVar1);
      }
    }
    FUN_40929564(param_1);
    mali_sys_free(param_1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 4092d1c0 FUN_4092d1c0 */

/* Boundary evidence: original MIPS .pdata 4092d1c0..4092d1df. Semantic name remains unreviewed. */

void FUN_4092d1c0(undefined4 param_1,undefined4 *param_2)

{
  FUN_4092f990(param_2,0);
  return;
}



/* 4092d1e0 FUN_4092d1e0 */

/* Boundary evidence: original MIPS .pdata 4092d1e0..4092d3db. Semantic name remains unreviewed. */

undefined4 FUN_4092d1e0(uint param_1,uint param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_5 != 0) {
      *(undefined4 *)(param_5 + 0x10) = 0x3008;
      return 0;
    }
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
    iVar2 = FUN_4092bc84(param_2,param_1,param_5);
    if (iVar2 == 0) {
      return 0;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
      if (param_3 == 0x3083) {
        uVar4 = *(uint *)(*(int *)(iVar2 + 0xb8) + 0x5c);
        if (((uVar4 & 1) != 0) || ((uVar4 & 4) != 0)) {
          if (*(int *)(iVar2 + 0xf0) == 0x305c) {
            return 1;
          }
          if (*(int *)(iVar2 + 0xf4) == 0x305c) {
            return 1;
          }
          if (*(int *)(iVar2 + 0xc) != 1) {
            return 1;
          }
          *(int *)(iVar2 + 0xdc) = param_4;
          return 1;
        }
        if (param_5 == 0) {
          return 0;
        }
        uVar3 = 0x300c;
LAB_4092d384:
        *(undefined4 *)(param_5 + 0x10) = uVar3;
        return 0;
      }
      if (param_3 == 0x3093) {
        if (param_4 == 0x3094) {
          if ((*(uint *)(*(int *)(iVar2 + 0xb8) + 0x6c) & 0x400) == 0) {
LAB_4092d33c:
            if (param_5 != 0) {
              *(undefined4 *)(param_5 + 0x10) = 0x3009;
              return 0;
            }
            return 0;
          }
LAB_4092d350:
          *(int *)(iVar2 + 0xe8) = param_4;
          return 1;
        }
        if (param_4 == 0x3095) goto LAB_4092d350;
      }
      else {
        if (param_3 != 0x3099) {
          if (param_5 == 0) {
            return 0;
          }
          uVar3 = 0x3004;
          goto LAB_4092d384;
        }
        if (param_4 == 0x309a) {
LAB_4092d2f8:
          *(int *)(iVar2 + 0xec) = param_4;
          return 1;
        }
        if (param_4 == 0x309b) {
          if ((*(uint *)(*(int *)(iVar2 + 0xb8) + 0x6c) & 0x200) == 0) goto LAB_4092d33c;
          goto LAB_4092d2f8;
        }
      }
      if (param_5 == 0) {
        return 0;
      }
      uVar3 = 0x300c;
      goto LAB_4092d264;
    }
  }
  if (param_5 == 0) {
    return 0;
  }
  uVar3 = 0x3001;
LAB_4092d264:
  *(undefined4 *)(param_5 + 0x10) = uVar3;
  return 0;
}



/* 4092d3dc FUN_4092d3dc */

/* Boundary evidence: original MIPS .pdata 4092d3dc..4092d687. Semantic name remains unreviewed. */

undefined4 FUN_4092d3dc(uint param_1,uint param_2,int param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_5 == 0) {
      return 0;
    }
    *(undefined4 *)(param_5 + 0x10) = 0x3008;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
    iVar2 = FUN_4092bc84(param_2,param_1,param_5);
    if (iVar2 == 0) {
      return 0;
    }
    if (param_4 == (undefined4 *)0x0) {
      if (param_5 == 0) {
        return 0;
      }
      *(undefined4 *)(param_5 + 0x10) = 0x300c;
      return 0;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
      if (param_3 < 0x3087) {
        if (param_3 != 0x3086) {
          if (param_3 < 0x3081) {
            if (param_3 != 0x3080) {
              if (param_3 == 0x3028) {
                uVar3 = *(undefined4 *)(*(int *)(iVar2 + 0xb8) + 0x2c);
              }
              else {
                if (param_3 == 0x3056) {
                  uVar3 = *(undefined4 *)(iVar2 + 0xc0);
                  goto LAB_4092d65c;
                }
                if (param_3 != 0x3057) {
                  if (param_3 != 0x3058) goto LAB_4092d610;
                  if (*(int *)(iVar2 + 0xc) != 1) {
                    return 1;
                  }
                  uVar3 = *(undefined4 *)(iVar2 + 0xd4);
                  goto LAB_4092d650;
                }
                uVar3 = *(undefined4 *)(iVar2 + 0xbc);
              }
LAB_4092d538:
              *param_4 = uVar3;
              return 1;
            }
            if (*(int *)(iVar2 + 0xc) != 1) {
              return 1;
            }
            uVar3 = *(undefined4 *)(iVar2 + 0xf0);
          }
          else {
            if (param_3 == 0x3081) {
              if (*(int *)(iVar2 + 0xc) != 1) {
                return 1;
              }
              uVar3 = *(undefined4 *)(iVar2 + 0xf4);
              goto LAB_4092d538;
            }
            if (param_3 == 0x3082) {
              if (*(int *)(iVar2 + 0xc) != 1) {
                return 1;
              }
              uVar3 = *(undefined4 *)(iVar2 + 0xd8);
              goto LAB_4092d65c;
            }
            if (param_3 != 0x3083) {
LAB_4092d610:
              if (param_5 == 0) {
                return 0;
              }
              *(undefined4 *)(param_5 + 0x10) = 0x3004;
              return 0;
            }
            if (*(int *)(iVar2 + 0xc) != 1) {
              return 1;
            }
            uVar3 = *(undefined4 *)(iVar2 + 0xdc);
          }
LAB_4092d650:
          *param_4 = uVar3;
          return 1;
        }
        uVar3 = *(undefined4 *)(iVar2 + 0xe4);
      }
      else if (param_3 == 0x3087) {
        uVar3 = *(undefined4 *)(iVar2 + 0xcc);
      }
      else {
        if (param_3 == 0x3088) {
          uVar3 = *(undefined4 *)(iVar2 + 0xc4);
          goto LAB_4092d650;
        }
        if (param_3 == 0x3090) {
          uVar3 = *(undefined4 *)(iVar2 + 0xd0);
        }
        else {
          if (param_3 == 0x3091) {
            uVar3 = *(undefined4 *)(iVar2 + 0xf8);
            goto LAB_4092d650;
          }
          if (param_3 == 0x3092) {
            uVar3 = *(undefined4 *)(iVar2 + 0xe0);
          }
          else {
            if (param_3 == 0x3093) {
              uVar3 = *(undefined4 *)(iVar2 + 0xe8);
              goto LAB_4092d650;
            }
            if (param_3 != 0x3099) goto LAB_4092d610;
            uVar3 = *(undefined4 *)(iVar2 + 0xec);
          }
        }
      }
LAB_4092d65c:
      *param_4 = uVar3;
      return 1;
    }
  }
  if (param_5 != 0) {
    *(undefined4 *)(param_5 + 0x10) = 0x3001;
  }
  return 0;
}



/* 4092d688 FUN_4092d688 */

/* Boundary evidence: original MIPS .pdata 4092d688..4092d83b. Semantic name remains unreviewed. */

void FUN_4092d688(undefined4 *param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uStack00000010;
  
  FUN_40935a70();
  iVar6 = param_1[0x2f];
  uVar7 = param_1[0x30];
  bVar1 = false;
  bVar2 = true;
  iVar8 = 0;
  uVar9 = 0;
  uStack00000010 = param_2;
  iVar3 = iVar6;
  if ((param_1[0x3d] == 0x305f) && ((param_1[0x3c] == 0x305d || (param_1[0x3c] == 0x305e)))) {
    bVar1 = true;
  }
  while ((iVar3 != 1 && (uVar5 = param_1[0x30], uVar5 != 1))) {
    if (bVar1) {
      param_1[0x2f] = (uint)param_1[0x2f] >> 1;
      param_1[0x30] = uVar5 >> 1;
      iVar3 = FUN_4092a0a4(param_1,uStack00000010,*(undefined4 *)(*(int *)(param_3 + 8) + 0x1c));
      if (iVar3 == 1) break;
    }
    else {
      if (bVar2) {
        iVar6 = param_1[0x2f];
        iVar3 = iVar6 - iVar8;
        if (iVar3 < 0) {
          iVar3 = iVar3 + 1;
        }
        iVar4 = uVar5 - uVar9;
        param_1[0x2f] = (iVar3 >> 1) + iVar8;
        if (iVar4 < 0) {
          iVar4 = iVar4 + 1;
        }
        param_1[0x30] = (iVar4 >> 1) + uVar9;
        uVar7 = uVar5;
        uVar5 = uVar9;
      }
      else {
        iVar8 = param_1[0x2f];
        param_1[0x2f] = ((uint)(iVar6 - iVar8) >> 1) + iVar8;
        param_1[0x30] = (uVar7 - uVar5 >> 1) + uVar5;
      }
      iVar3 = FUN_4092a0a4(param_1,uStack00000010,*(undefined4 *)(*(int *)(param_3 + 8) + 0x1c));
      uVar9 = uVar5;
      if (iVar3 == 1) {
        if (((uint)(iVar6 - param_1[0x2f]) < 9) && (uVar7 - param_1[0x30] < 9)) break;
        FUN_4092d010(param_1);
        bVar2 = false;
      }
      else {
        bVar2 = true;
        if ((iVar6 == iVar8) && (uVar7 == uVar5)) break;
      }
    }
    iVar3 = param_1[0x2f];
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935aa8(0x18);
}



/* 4092d83c FUN_4092d83c */

/* Boundary evidence: original MIPS .pdata 4092d83c..4092d907. Semantic name remains unreviewed. */

uint FUN_4092d83c(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  if (param_2[3] == 0x30a0) {
    piVar3 = (int *)param_2[1];
  }
  else {
    if (param_2[3] != 0x30a1) {
      return 0;
    }
    piVar3 = (int *)*param_2;
  }
  if ((piVar3 != (int *)0x0) && (piVar3[3] != 0)) {
    if (param_1 == 0x3059) {
      uVar1 = FUN_4092bfc8(*piVar3,0,1);
      iVar2 = piVar3[1];
    }
    else {
      if (param_1 != 0x305a) {
        param_2[4] = 0x300c;
        return 0;
      }
      uVar1 = FUN_4092bfc8(*piVar3,0,1);
      iVar2 = piVar3[2];
    }
    uVar1 = FUN_4092bfc8(iVar2,uVar1,2);
    if (uVar1 != 0) {
      return uVar1 | 0x20000000;
    }
  }
  return 0;
}



/* 4092d908 FUN_4092d908 */

/* Boundary evidence: original MIPS .pdata 4092d908..4092d98f. Semantic name remains unreviewed. */

undefined4 FUN_4092d908(uint param_1,undefined4 *param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  
  if (param_3 == 1) {
    param_2[0x2a] = 0;
  }
  iVar2 = param_2[0x27];
  param_2[0x27] = iVar2 + -1;
  if ((param_2[0x28] == 1) && (iVar2 + -1 == 0)) {
    param_2[0x27] = 1;
  }
  iVar2 = FUN_4092d098(param_2,param_4);
  if (iVar2 == 0) {
    uVar1 = FUN_4092bd54((int)param_2,param_1,2,param_4,unaff_s1,unaff_s0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 4092d990 FUN_4092d990 */

/* Boundary evidence: original MIPS .pdata 4092d990..4092dd13. Semantic name remains unreviewed. */

void FUN_4092d990(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  BOOL BVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uStack00000020;
  uint uStack00000024;
  HWND in_stack_00000058;
  HANDLE in_stack_0000005c;
  int *in_stack_00000060;
  undefined4 in_stack_00000068;
  
  FUN_40935a10();
  uStack00000020 = 0x1000;
  uStack00000024 = 0x1000;
  piVar4 = (int *)mali_sys_malloc(0x10c);
  if (piVar4 == (int *)0x0) {
    if (param_1 != (int *)0x0) {
      param_1[4] = 0x3003;
    }
    goto LAB_4092dd08;
  }
  mali_sys_memset(piVar4,0,0x10c);
  FUN_4092cbf8((int)piVar4,param_4,&stack0x0000005c,param_3);
  if (param_3 == 0) {
    if (in_stack_00000058 == (HWND)0x0) {
      iVar5 = FUN_40929244();
      if (iVar5 != 0) {
        *piVar4 = iVar5;
        piVar4[0x29] = 1;
        goto LAB_4092da8c;
      }
LAB_4092da28:
      if (param_1 == (int *)0x0) goto LAB_4092da38;
      iVar5 = 0x3003;
    }
    else {
      BVar6 = IsWindow(in_stack_00000058);
      if (BVar6 != 0) {
        iVar5 = FUN_4092b698((int)in_stack_00000058);
        if (iVar5 != 1) {
          *piVar4 = (int)in_stack_00000058;
          goto LAB_4092da8c;
        }
        goto LAB_4092da28;
      }
      if (param_1 == (int *)0x0) goto LAB_4092da38;
      iVar5 = 0x300b;
    }
LAB_4092da34:
    param_1[4] = iVar5;
  }
  else {
LAB_4092da8c:
    iVar5 = FUN_4092cd18((int)param_1,in_stack_00000060,param_4,(int)piVar4);
    if (iVar5 != 0) {
      if (param_3 == 0) {
        piVar4[0x38] = 1;
        piVar4[0x34] = 1;
        piVar4[0x3e] = 1;
        FUN_40928940(piVar4,(int *)&stack0x00000020,(int *)&stack0x00000024);
        uVar8 = uStack00000020;
        if (uStack00000020 == 0) {
          uVar8 = 1;
        }
        uVar9 = uStack00000024;
        if (uStack00000024 == 0) {
          uVar9 = 1;
        }
      }
      else if (param_3 == 2) {
        FUN_40928c4c(in_stack_0000005c,&stack0x00000020,&stack0x00000024);
        uVar8 = uStack00000020;
        uVar9 = uStack00000024;
      }
      else {
        uVar8 = uStack00000020;
        uVar9 = uStack00000024;
        if (param_3 == 1) {
          iVar5 = piVar4[0x3c];
          if (iVar5 == 0x305c) {
            if (piVar4[0x3d] == 0x305c) {
LAB_4092dc28:
              if ((((piVar4[0x3d] == 0x305f) && ((iVar5 == 0x305d || (iVar5 == 0x305e)))) &&
                  (((uStack00000020 - 1 & uStack00000020) != 0 ||
                   ((uStack00000024 - 1 & uStack00000024) != 0)))) &&
                 ((*(uint *)(param_4 + 0x5c) & 1) != 0)) {
                bVar2 = false;
                bVar3 = false;
                uVar10 = 1;
                uVar12 = 1;
LAB_4092dc94:
                uVar11 = uVar12;
                if (!bVar2) goto LAB_4092dcac;
                if (!bVar3) goto LAB_4092dcd0;
              }
              goto LAB_4092db28;
            }
          }
          else if (piVar4[0x3d] != 0x305c) goto LAB_4092dc28;
          if (param_1 != (int *)0x0) {
            iVar5 = 0x3009;
            goto LAB_4092da34;
          }
          goto LAB_4092da38;
        }
      }
LAB_4092db28:
      piVar4[0x2f] = uVar8;
      piVar4[0x30] = uVar9;
      piVar4[0x2d] = param_2;
      iVar5 = FUN_4092a0a4(piVar4,in_stack_00000068,*(undefined4 *)(param_1[2] + 0x1c));
      if ((iVar5 == 0) &&
         ((piVar4[0x35] != 1 ||
          (iVar5 = FUN_4092d688(piVar4,in_stack_00000068,(int)param_1), iVar5 == 0)))) {
LAB_4092dcf0:
        FUN_4092d098(piVar4,param_1);
        param_1[4] = 0x3003;
      }
      else {
        if (param_3 == 0) {
          mali_frame_builder_use_surface_deps(piVar4[2],0);
        }
        iVar5 = 0;
        *(undefined2 *)(piVar4 + 0x1c) = 0;
        piVar4[0x1b] = 0;
        piVar1 = piVar4;
        do {
          piVar1[7] = 0;
          iVar7 = mali_ds_consumer_allocate
                            (*(undefined4 *)(param_1[2] + 0x1c),piVar1 + 5,FUN_4092d1c0,0);
          piVar1[9] = iVar7;
          if (iVar7 == 0) goto LAB_4092dcf0;
          iVar5 = iVar5 + 1;
          piVar1 = piVar1 + 5;
        } while (iVar5 < 4);
        piVar4[0x27] = 1;
      }
      goto LAB_4092dd08;
    }
  }
LAB_4092da38:
  FUN_4092d098(piVar4,param_1);
LAB_4092dd08:
                    /* WARNING: Subroutine does not return */
  FUN_40935a40(0x28);
LAB_4092dcac:
  uVar12 = uVar10 << 1;
  if (uVar8 <= uVar12) {
    bVar2 = true;
    uVar8 = uVar10;
  }
  uVar10 = uVar12;
  uVar12 = uVar11;
  if (!bVar3) {
LAB_4092dcd0:
    uVar12 = uVar11 << 1;
    if (uVar9 <= uVar12) {
      bVar3 = true;
      uVar9 = uVar11;
    }
  }
  goto LAB_4092dc94;
}



/* 4092dd14 FUN_4092dd14 */

/* Boundary evidence: original MIPS .pdata 4092dd14..4092ddf7. Semantic name remains unreviewed. */

undefined4 FUN_4092dd14(uint param_1,uint param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_3 != (int *)0x0) {
    iVar1 = FUN_4092bb88(param_1);
    if (iVar1 == 0) {
      param_3[4] = 0x3008;
    }
    else {
      if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
        puVar2 = (undefined4 *)FUN_4092bc84(param_2,param_1,(int)param_3);
        if (puVar2 == (undefined4 *)0x0) {
          return 0;
        }
        if ((*(uint *)(iVar1 + 0x20) & 2) == 0) goto LAB_4092ddc0;
      }
      param_3[4] = 0x3001;
    }
    return 0;
  }
  puVar2 = (undefined4 *)FUN_4092ba28(param_2,param_1);
LAB_4092ddc0:
  FUN_4092d908(param_1,puVar2,1,param_3);
  return 1;
}



/* 4092ddf8 FUN_4092ddf8 */

/* Boundary evidence: original MIPS .pdata 4092ddf8..4092dff3. Semantic name remains unreviewed. */

uint FUN_4092ddf8(uint param_1,uint param_2,HANDLE param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined1 auStack_78 [88];
  
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_5 == (int *)0x0) {
      return 0;
    }
    param_5[4] = 0x3008;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
    piVar2 = (int *)FUN_4092bad8(param_2,param_1);
    if (piVar2 == (int *)0x0) {
      if (param_5 == (int *)0x0) {
        return 0;
      }
      param_5[4] = 0x3005;
      return 0;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
      if ((piVar2[0x1b] & 2U) != 0) {
        iVar3 = GetObjectW(param_3,0x54,auStack_78);
        if (iVar3 == 0) {
          if (param_5 == (int *)0x0) {
            return 0;
          }
          iVar1 = 0x300a;
        }
        else {
          iVar3 = FUN_4092b5fc((int)param_3);
          if (iVar3 != 1) {
            iVar3 = FUN_40929fc4(param_3,piVar2);
            if (iVar3 == 0) {
              if (param_5 == (int *)0x0) {
                return 0;
              }
              iVar1 = 0x3009;
              goto LAB_4092dfc8;
            }
            puVar4 = (undefined4 *)FUN_4092d990(param_5,iVar1,2,(int)piVar2);
            if (puVar4 == (undefined4 *)0x0) {
              return 0;
            }
            iVar1 = FUN_40930448((int)puVar4);
            if (((iVar1 != 0) && (uVar5 = FUN_4092c4e8((int)puVar4,param_1,2), uVar5 != 0)) &&
               ((uVar5 | 0x20000000) != 0)) {
              return uVar5 | 0x20000000;
            }
            puVar4[0x27] = 0;
            FUN_4092d098(puVar4,param_5);
          }
          if (param_5 == (int *)0x0) {
            return 0;
          }
          iVar1 = 0x3003;
        }
LAB_4092dfc8:
        param_5[4] = iVar1;
        return 0;
      }
      if (param_5 == (int *)0x0) {
        return 0;
      }
      iVar1 = 0x3009;
      goto LAB_4092de74;
    }
  }
  if (param_5 == (int *)0x0) {
    return 0;
  }
  iVar1 = 0x3001;
LAB_4092de74:
  param_5[4] = iVar1;
  return 0;
}



/* 4092dff4 FUN_4092dff4 */

/* Boundary evidence: original MIPS .pdata 4092dff4..4092e183. Semantic name remains unreviewed. */

uint FUN_4092dff4(uint param_1,int param_2,int param_3,uint param_4,int *param_5,int *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_6 == (int *)0x0) {
      return 0;
    }
    param_6[4] = 0x3008;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
    puVar2 = (undefined4 *)FUN_4092bad8(param_4,param_1);
    if (puVar2 == (undefined4 *)0x0) {
      if (param_6 == (int *)0x0) {
        return 0;
      }
      param_6[4] = 0x3005;
      return 0;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
      if (param_2 != 0x3096) {
        if (param_6 == (int *)0x0) {
          return 0;
        }
        param_6[4] = 0x300c;
        return 0;
      }
      if (param_3 == 0) {
        if (param_6 == (int *)0x0) {
          return 0;
        }
        iVar1 = 0x300c;
      }
      else {
        puVar2 = (undefined4 *)FUN_40927814(iVar1,param_3,puVar2,param_5);
        if (puVar2 == (undefined4 *)0x0) {
          return 0;
        }
        uVar3 = FUN_4092c4e8((int)puVar2,param_1,2);
        if ((uVar3 != 0) && ((uVar3 | 0x20000000) != 0)) {
          return uVar3 | 0x20000000;
        }
        puVar2[0x27] = 0;
        FUN_4092d098(puVar2,param_6);
        if (param_6 == (int *)0x0) {
          return 0;
        }
        iVar1 = 0x3003;
      }
      param_6[4] = iVar1;
      return 0;
    }
  }
  if (param_6 != (int *)0x0) {
    param_6[4] = 0x3001;
  }
  return 0;
}



/* 4092e184 FUN_4092e184 */

/* Boundary evidence: original MIPS .pdata 4092e184..4092e2db. Semantic name remains unreviewed. */

void FUN_4092e184(uint param_1,uint param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  FUN_40935ae0();
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_4 != (int *)0x0) {
      param_4[4] = 0x3008;
    }
    goto LAB_4092e2d4;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) == 0) {
LAB_4092e1e0:
    if (param_4 == (int *)0x0) goto LAB_4092e2d4;
    iVar1 = 0x3001;
  }
  else {
    iVar2 = FUN_4092bad8(param_2,param_1);
    if (iVar2 == 0) {
      if (param_4 != (int *)0x0) {
        param_4[4] = 0x3005;
      }
      goto LAB_4092e2d4;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) != 0) goto LAB_4092e1e0;
    if ((*(uint *)(iVar2 + 0x6c) & 1) != 0) {
      puVar3 = (undefined4 *)FUN_4092d990(param_4,iVar1,1,iVar2);
      if ((puVar3 != (undefined4 *)0x0) &&
         ((uVar4 = FUN_4092c4e8((int)puVar3,param_1,2), uVar4 == 0 || ((uVar4 | 0x20000000) == 0))))
      {
        puVar3[0x27] = 0;
        FUN_4092d098(puVar3,param_4);
        if (param_4 != (int *)0x0) {
          param_4[4] = 0x3003;
        }
      }
      goto LAB_4092e2d4;
    }
    if (param_4 == (int *)0x0) goto LAB_4092e2d4;
    iVar1 = 0x3009;
  }
  param_4[4] = iVar1;
LAB_4092e2d4:
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x28);
}



/* 4092e2dc FUN_4092e2dc */

/* Boundary evidence: original MIPS .pdata 4092e2dc..4092e463. Semantic name remains unreviewed. */

uint FUN_4092e2dc(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_5 == (int *)0x0) {
      return 0;
    }
    param_5[4] = 0x3008;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
    iVar2 = FUN_4092bad8(param_2,param_1);
    if (iVar2 == 0) {
      if (param_5 == (int *)0x0) {
        return 0;
      }
      param_5[4] = 0x3005;
      return 0;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
      if ((*(uint *)(iVar2 + 0x6c) & 4) != 0) {
        puVar3 = (undefined4 *)FUN_4092d990(param_5,iVar1,0,iVar2);
        if (puVar3 == (undefined4 *)0x0) {
          return 0;
        }
        uVar4 = FUN_4092c4e8((int)puVar3,param_1,2);
        if ((uVar4 != 0) && ((uVar4 | 0x20000000) != 0)) {
          return uVar4 | 0x20000000;
        }
        puVar3[0x27] = 0;
        FUN_4092d098(puVar3,param_5);
        if (param_5 == (int *)0x0) {
          return 0;
        }
        param_5[4] = 0x3003;
        return 0;
      }
      if (param_5 == (int *)0x0) {
        return 0;
      }
      iVar1 = 0x3009;
      goto LAB_4092e358;
    }
  }
  if (param_5 == (int *)0x0) {
    return 0;
  }
  iVar1 = 0x3001;
LAB_4092e358:
  param_5[4] = iVar1;
  return 0;
}



/* 4092e464 FUN_4092e464 */

/* Boundary evidence: original MIPS .pdata 4092e464..4092e4f7. Semantic name remains unreviewed. */

undefined * FUN_4092e464(int param_1)

{
  int iVar1;
  int iVar2;
  undefined **ppuVar3;
  
  if (param_1 != 0) {
    ppuVar3 = &PTR_s_eglCreateImageKHR_4092386c;
    iVar2 = 0;
    do {
      iVar1 = mali_sys_strcmp(*ppuVar3,param_1);
      if (iVar1 == 0) {
        return (&PTR_eglCreateImageKHR_40923870)[iVar2 * 2];
      }
      iVar2 = iVar2 + 1;
      ppuVar3 = ppuVar3 + 2;
    } while (iVar2 < 3);
  }
  return (undefined *)0x0;
}



/* 4092e52c FUN_4092e52c */

/* Boundary evidence: original MIPS .pdata 4092e52c..4092e547. Semantic name remains unreviewed. */

void FUN_4092e52c(void)

{
  mali_frame_builder_reset();
  return;
}



/* 4092e548 FUN_4092e548 */

/* Boundary evidence: original MIPS .pdata 4092e548..4092e5ab. Semantic name remains unreviewed. */

int FUN_4092e548(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = mali_frame_builder_flush(param_1,0,0);
  if (iVar1 == 0) {
    mali_frame_builder_wait(param_1);
    iVar1 = 0;
  }
  else {
    mali_frame_builder_reset();
  }
  return iVar1;
}



/* 4092e5ac FUN_4092e5ac */

/* Boundary evidence: original MIPS .pdata 4092e5ac..4092e5eb. Semantic name remains unreviewed. */

void FUN_4092e5ac(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  
  FUN_40935b30();
  uVar1 = 0;
  puVar2 = (undefined4 *)(param_2 + 0xc);
  do {
    mali_frame_builder_set_attachment(param_1,uVar1,*puVar2);
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 < 3);
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 4092e5ec FUN_4092e5ec */

/* Boundary evidence: original MIPS .pdata 4092e5ec..4092e647. Semantic name remains unreviewed. */

void FUN_4092e5ec(undefined4 param_1,int param_2)

{
  mali_frame_builder_set_attachment(param_1,0,*(undefined4 *)(param_2 + 0xc));
  mali_frame_builder_set_attachment(param_1,1,*(undefined4 *)(param_2 + 0x10));
  mali_frame_builder_set_attachment(param_1,2,*(undefined4 *)(param_2 + 0x14));
  return;
}



/* 4092e648 FUN_4092e648 */

/* Boundary evidence: original MIPS .pdata 4092e648..4092e68f. Semantic name remains unreviewed. */

void FUN_4092e648(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  FUN_40935b30();
  uVar2 = 0;
  do {
    uVar1 = mali_frame_builder_get_attachment(param_1,uVar2);
    uVar2 = uVar2 + 1;
    param_2[3] = uVar1;
    *param_2 = 0;
    param_2 = param_2 + 1;
  } while (uVar2 < 3);
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 4092e690 FUN_4092e690 */

/* Boundary evidence: original MIPS .pdata 4092e690..4092e7a7. Semantic name remains unreviewed. */

void FUN_4092e690(int param_1,int param_2,int param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  FUN_40935ae0();
  uVar1 = *(ushort *)(param_1 + 0x70);
  iVar5 = (uVar1 + 1) * 0x14 + param_1;
  if ((param_3 == 1) && (iVar5 != 0)) {
    uVar3 = (uint)*(ushort *)(param_1 + 0x72);
    uVar4 = uVar1 + 1;
    if (uVar3 == 0) {
      trap(0x1c00);
    }
    if ((uVar3 == 0xffffffff) && (uVar4 == 0x80000000)) {
      trap(0x1800);
    }
    *(short *)(param_1 + 0x70) = (short)(uVar4 % uVar3);
    *(undefined4 *)(iVar5 + 8) = 1;
  }
  if (param_2 == 1) {
    iVar2 = mali_frame_builder_flush(*(undefined4 *)(param_1 + 8),param_4);
    if (iVar2 == 0) {
      if (*(int *)(param_1 + 0xe8) == 0x3095) {
        mali_frame_builder_wait(*(undefined4 *)(param_1 + 8));
      }
      if (param_3 == 1) {
        mali_frame_builder_reset(*(undefined4 *)(param_1 + 8));
      }
      goto LAB_4092e79c;
    }
    if ((param_3 != 1) || (iVar5 == 0)) goto LAB_4092e79c;
  }
  else {
    iVar2 = mali_frame_builder_swap(*(undefined4 *)(param_1 + 8),param_4,iVar5);
    if ((iVar2 == 0) || (mali_frame_builder_reset(*(undefined4 *)(param_1 + 8)), param_3 != 1))
    goto LAB_4092e79c;
  }
  *(ushort *)(param_1 + 0x70) = uVar1;
  *(undefined4 *)(iVar5 + 8) = 0;
LAB_4092e79c:
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x10);
}



/* 4092e7a8 FUN_4092e7a8 */

/* Boundary evidence: original MIPS .pdata 4092e7a8..4092e9db. Semantic name remains unreviewed. */

int FUN_4092e7a8(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 local_38 [4];
  
  memset(local_38,0,0x10);
  iVar4 = *(int *)(param_2 + 100);
  if ((((iVar4 < 0) || (iVar4 < 2)) || (iVar4 == 4)) || (iVar4 != 0x10)) {
    uVar5 = 0;
  }
  else {
    uVar5 = 2;
  }
  iVar4 = mali_frame_builder_alloc(param_1,uVar5,4,1,0);
  if (iVar4 != 0) {
    uVar6 = 0;
    puVar7 = local_38;
    do {
      *puVar7 = *(undefined4 *)((param_3 - (int)local_38) + (int)puVar7);
      NKDbgPrintfW(L"__egl_mali_create_frame_builder::color_target[%d] == %08X\r\n",uVar6);
      uVar6 = uVar6 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar6 < 4);
    iVar1 = mali_render_attachment_alloc(local_38,4,1,uVar5,0);
    iVar2 = mali_render_attachment_alloc(0,0,0,uVar5,1);
    iVar3 = mali_render_attachment_alloc(0,0,0,uVar5,2);
    if (((iVar1 != 0) && (iVar2 != 0)) && (iVar3 != 0)) {
      mali_render_attachment_set_target(iVar1,0,local_38[0],0);
      mali_frame_builder_set_clear_value(iVar4,1,0xffffff,0);
      mali_frame_builder_set_clear_value(iVar4,2,0,0);
      mali_frame_builder_set_attachment(iVar4,0,iVar1);
      mali_frame_builder_set_attachment(iVar4,1,iVar2);
      mali_frame_builder_set_attachment(iVar4,2,iVar3);
      return iVar4;
    }
    mali_frame_builder_free(iVar4);
    if (iVar1 != 0) {
      mali_render_attachment_free(iVar1);
    }
    if (iVar2 != 0) {
      mali_render_attachment_free(iVar2);
    }
    if (iVar3 != 0) {
      mali_render_attachment_free(iVar3);
    }
  }
  return 0;
}



/* 4092e9dc FUN_4092e9dc */

/* Boundary evidence: original MIPS .pdata 4092e9dc..4092ea4b. Semantic name remains unreviewed. */

int FUN_4092e9dc(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x34);
  if (iVar1 == 0) {
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      if (*(int *)(param_1 + 0x48) == 0) {
        *(int *)(param_1 + 0x48) = param_1;
      }
      (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x44))
      ;
    }
    mali_surface_free(param_1);
  }
  return iVar1;
}



/* 4092ea4c FUN_4092ea4c */

/* Boundary evidence: original MIPS .pdata 4092ea4c..4092eaa3. Semantic name remains unreviewed. */

undefined4 FUN_4092ea4c(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == -1) {
    if (param_1[1] == 0x3f) {
      uVar1 = 0;
    }
    else {
      uVar1 = __m200_texel_format_get_bpp();
    }
  }
  else {
    uVar1 = __mali_pixel_format_get_bpp(*param_1);
  }
  return uVar1;
}



/* 4092ead0 FUN_4092ead0 */

/* Boundary evidence: original MIPS .pdata 4092ead0..4092eb07. Semantic name remains unreviewed. */

int FUN_4092ead0(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_1[1] == 0) {
    iVar1 = mali_mem_mali_addr_get_full();
  }
  else {
    iVar1 = *param_1 + param_2;
  }
  return iVar1;
}



/* 4092eb08 FUN_4092eb08 */

/* Boundary evidence: original MIPS .pdata 4092eb08..4092ee9b. Semantic name remains unreviewed. */

void FUN_4092eb08(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  
  FUN_40935a10();
  param_7 = 0xb08b06c0;
  param_8 = 0x438002c3;
  param_9 = 0x40010d00;
  param_10 = 0x1c08;
  uVar1 = mali_frame_builder_get_base_ctx(param_2);
  iVar2 = mali_mem_alloc(uVar1,0x10,0x40,0x34);
  if (iVar2 != 0) {
    mali_frame_builder_add_gp_job_mem(param_2,iVar2);
    mali_mem_write(iVar2,0,&param_7,0x10);
    if (*(int *)(iVar2 + 4) == 0) {
      mali_mem_mali_addr_get_full(iVar2,0);
    }
    iVar2 = mali_gp_job_add_vs_cmd(param_4);
    if ((iVar2 == 0) &&
       (puVar3 = (undefined4 *)mali_mem_alloc(uVar1,0xc,0x40,0x34), puVar3 != (undefined4 *)0x0)) {
      mali_frame_builder_add_gp_job_mem(param_2,puVar3);
      mali_mem_write(puVar3,0,param_3,0x24);
      iVar2 = mali_mem_alloc(uVar1,0x88,0x40,0x3c);
      if (iVar2 != 0) {
        mali_frame_builder_add_gp_job_mem(param_2,iVar2);
        puVar4 = (undefined4 *)mali_mem_ptr_map_area(iVar2,0,0x88,0x40);
        if (puVar4 != (undefined4 *)0x0) {
          if (puVar3[1] == 0) {
            uVar1 = mali_mem_mali_addr_get_full(puVar3,0);
          }
          else {
            uVar1 = *puVar3;
          }
          *puVar4 = uVar1;
          puVar4[1] = 0x6002;
          piVar6 = (int *)param_1[2];
          if (piVar6[1] == 0) {
            iVar5 = mali_mem_mali_addr_get_full(piVar6,*param_1);
          }
          else {
            iVar5 = *piVar6 + *param_1;
          }
          puVar4[0x20] = iVar5;
          puVar4[0x21] = 0x8020;
          mali_mem_ptr_unmap_area(iVar2);
          if (*(int *)(iVar2 + 4) == 0) {
            mali_mem_mali_addr_get_full(iVar2,0);
          }
          iVar2 = mali_gp_job_add_vs_cmd(param_4);
          if (((((iVar2 == 0) && (iVar2 = mali_gp_job_add_vs_cmd(param_4), iVar2 == 0)) &&
               (iVar2 = mali_gp_job_add_vs_cmd(param_4), iVar2 == 0)) &&
              ((iVar2 = mali_gp_job_add_vs_cmd(param_4), iVar2 == 0 &&
               (iVar2 = mali_gp_job_add_vs_cmd(param_4), iVar2 == 0)))) &&
             (iVar2 = mali_gp_job_add_vs_cmd(param_4), iVar2 == 0)) {
            uVar1 = mali_frame_builder_get_gp_job(param_2);
            if (param_1[9] == 1) {
              iVar2 = mali_gp_job_add_plbu_cmd(uVar1);
              if (iVar2 != 0) goto LAB_4092ee94;
              param_1[9] = 0;
            }
            mali_frame_builder_get_tile_list_block_scale(param_2);
            iVar2 = mali_gp_job_add_plbu_cmd(uVar1);
            if (((iVar2 == 0) && (iVar2 = mali_gp_job_add_plbu_cmd(uVar1), iVar2 == 0)) &&
               (iVar2 = mali_gp_job_add_plbu_cmd(uVar1), iVar2 == 0)) {
              mali_gp_job_add_plbu_cmd(uVar1);
            }
          }
        }
      }
    }
  }
LAB_4092ee94:
                    /* WARNING: Subroutine does not return */
  FUN_40935a40(0x28);
}



/* 4092ee9c FUN_4092ee9c */

/* Boundary evidence: original MIPS .pdata 4092ee9c..4092efaf. Semantic name remains unreviewed. */

void FUN_4092ee9c(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  FUN_40935a10();
  iVar1 = mali_frame_builder_get_rsw_cache(param_2);
  iVar2 = __mali_rsw_cache_commit(iVar1,param_3,1);
  param_1[4] = iVar2;
  if (iVar2 == -1) {
    __mali_rsw_cache_flush(iVar1);
    uVar3 = mali_frame_builder_get_base_ctx(param_2);
    iVar2 = mali_mem_alloc(uVar3,0x4000,0x40,1);
    if (iVar2 != 0) {
      mali_frame_builder_add_frame_mem(param_2,iVar2);
      *(int *)(iVar1 + 4) = iVar2;
      iVar2 = __mali_rsw_cache_commit(iVar1,param_3,1);
      param_1[4] = iVar2;
      param_1[9] = 1;
      piVar4 = *(int **)(iVar1 + 4);
      if (piVar4[1] == 0) {
        iVar1 = mali_mem_mali_addr_get_full(piVar4,0);
      }
      else {
        iVar1 = *piVar4;
      }
      piVar4 = (int *)param_1[2];
      param_1[7] = iVar1;
      if (piVar4[1] == 0) {
        iVar1 = mali_mem_mali_addr_get_full(piVar4,*param_1);
      }
      else {
        iVar1 = *piVar4 + *param_1;
      }
      param_1[8] = iVar1 + param_1[6] * -0x10;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935a40(0x10);
}



/* 4092efb0 FUN_4092efb0 */

/* Boundary evidence: original MIPS .pdata 4092efb0..4092f09f. Semantic name remains unreviewed. */

undefined4 FUN_4092efb0(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  *param_1 = 0;
  param_1[1] = 0x40;
  uVar1 = mali_frame_builder_get_base_ctx(param_2);
  iVar2 = mali_mem_alloc(uVar1,0x70,0x40,9);
  param_1[3] = iVar2;
  param_1[2] = iVar2;
  if (iVar2 == 0) {
    *param_1 = 0;
    uVar1 = 0xffffffff;
    param_1[1] = 0;
  }
  else {
    mali_frame_builder_add_frame_mem(param_2,iVar2);
    param_1[6] = 0;
    iVar2 = mali_frame_builder_get_rsw_cache(param_2);
    param_1[9] = 1;
    piVar3 = *(int **)(iVar2 + 4);
    if (piVar3[1] == 0) {
      iVar2 = mali_mem_mali_addr_get_full(piVar3,0);
    }
    else {
      iVar2 = *piVar3;
    }
    piVar3 = (int *)param_1[2];
    param_1[7] = iVar2;
    if (piVar3[1] == 0) {
      iVar2 = mali_mem_mali_addr_get_full(piVar3,*param_1);
    }
    else {
      iVar2 = *piVar3 + *param_1;
    }
    param_1[8] = iVar2;
    uVar1 = 0;
  }
  return uVar1;
}



/* 4092f0a0 FUN_4092f0a0 */

/* Boundary evidence: original MIPS .pdata 4092f0a0..4092f1bb. Semantic name remains unreviewed. */

undefined4 FUN_4092f0a0(uint *param_1,int param_2)

{
  uint uVar1;
  
  m200_texture_descriptor_set_defaults(param_1);
  param_1[1] = param_1[1] & 0xfffffcff | 0x80;
  param_1[2] = param_1[2] | 0x1800;
  *param_1 = *param_1 & 0xffffff3f;
  uVar1 = mali_pixel_to_texel_format(*(undefined4 *)(*(int *)(param_2 + 0xb8) + 0x80));
  *param_1 = uVar1 | *param_1 & 0xffffffc0;
  param_1[2] = param_1[2] & 0x3fffff | *(int *)(param_2 + 0xbc) << 0x16;
  uVar1 = param_1[3] & 0xfffffff8 | *(uint *)(param_2 + 0xbc) >> 10;
  param_1[3] = uVar1;
  param_1[3] = *(int *)(param_2 + 0xc0) << 3 | uVar1 & 0xffff0007;
  param_1[6] = param_1[6] & 0xffff9fff;
  NKDbgPrintfW(L"%s %d\r\n",L"src/egl/egl_platform_win32.c",0x8d0);
  return 0xffffffff;
}



/* 4092f1bc FUN_4092f1bc */

/* Boundary evidence: original MIPS .pdata 4092f1bc..4092f40f. Semantic name remains unreviewed. */

void FUN_4092f1bc(uint *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
                 )

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  
  puVar1 = (undefined4 *)mali_render_attachment_get_target(param_2,param_5,0);
  m200_texture_descriptor_set_defaults(param_1);
  param_1[1] = param_1[1] & 0xfffffcff | 0x80;
  param_1[2] = param_1[2] | 0x1800;
  *param_1 = *param_1 & 0xffffff3f | (uint)(param_3 == 1) << 6;
  uVar6 = puVar1[6];
  if (uVar6 == 0x2c) {
    uVar6 = 0x32;
  }
  uVar4 = (uint)*(ushort *)(puVar1 + 3);
  uVar2 = FUN_4092ea4c(puVar1 + 5);
  if ((uVar2 & 0xfffffff8) != 0) {
    uVar2 = FUN_4092ea4c(puVar1 + 5);
    uVar4 = (uint)*(ushort *)(puVar1 + 4) / (uVar2 >> 3);
    if (uVar2 >> 3 == 0) {
      trap(0x1c00);
    }
  }
  *param_1 = *param_1 & 0xffffffc0 | uVar6;
  param_1[2] = param_1[2] & 0x3fffff | uVar4 << 0x16;
  uVar6 = (int)uVar4 >> 10 | param_1[3] & 0xfffffff8;
  param_1[3] = uVar6;
  param_1[3] = (uint)*(ushort *)((int)puVar1 + 0xe) << 3 | uVar6 & 0xffff0007;
  param_1[6] = puVar1[8] << 0xd | param_1[6] & 0xffff9fff;
  mali_surface_access_lock(puVar1);
  piVar5 = *(int **)*puVar1;
  if (piVar5[1] == 0) {
    iVar3 = mali_mem_mali_addr_get_full(piVar5,puVar1[1]);
  }
  else {
    iVar3 = *piVar5 + puVar1[1];
  }
  param_1[6] = (iVar3 << 0x18 ^ param_1[6]) & 0x3fffffff ^ iVar3 << 0x18;
  piVar5 = *(int **)*puVar1;
  if (piVar5[1] == 0) {
    uVar6 = mali_mem_mali_addr_get_full(piVar5,puVar1[1]);
  }
  else {
    uVar6 = *piVar5 + puVar1[1];
  }
  param_1[7] = param_1[7] & 0xff000000 | uVar6 >> 8;
  mali_surface_access_unlock(puVar1);
  return;
}



/* 4092f410 FUN_4092f410 */

/* Boundary evidence: original MIPS .pdata 4092f410..4092f45f. Semantic name remains unreviewed. */

void FUN_4092f410(int *param_1)

{
  if (*param_1 != 0) {
    FUN_4092e9dc(*param_1);
  }
  if (param_1[3] != 0) {
    mali_render_attachment_free();
  }
  mali_sys_free(param_1);
  return;
}



/* 4092f460 FUN_4092f460 */

/* Boundary evidence: original MIPS .pdata 4092f460..4092f563. Semantic name remains unreviewed. */

void FUN_4092f460(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  FUN_40935a10();
  memset(&stack0x00000010,0,0x10);
  iVar1 = mali_frame_builder_get_attachment(param_1,0);
  iVar2 = mali_frame_builder_get_attachment(param_1,1);
  iVar3 = mali_frame_builder_get_attachment(param_1,2);
  uVar6 = 0;
  puVar7 = (undefined4 *)&stack0x00000010;
  do {
    mali_render_attachment_rotate_attachment(iVar1);
    uVar4 = mali_render_attachment_get_target(iVar1,0,0);
    *puVar7 = uVar4;
    NKDbgPrintfW(L"__egl_mali_destroy_frame_builder::color_target[%d] == %08X\r\n",uVar6,uVar4);
    uVar6 = uVar6 + 1;
    puVar7 = puVar7 + 1;
  } while (uVar6 < 4);
  if (iVar1 != 0) {
    mali_render_attachment_free(iVar1);
  }
  if (iVar2 != 0) {
    mali_render_attachment_free(iVar2);
  }
  if (iVar3 != 0) {
    mali_render_attachment_free(iVar3);
  }
  piVar5 = (int *)&stack0x00000010;
  iVar1 = 4;
  do {
    if (*piVar5 != 0) {
      FUN_4092e9dc(*piVar5);
    }
    iVar1 = iVar1 + -1;
    piVar5 = piVar5 + 1;
  } while (iVar1 != 0);
  mali_frame_builder_free(param_1);
                    /* WARNING: Subroutine does not return */
  FUN_40935a40(0x20);
}



/* 4092f564 FUN_4092f564 */

/* Boundary evidence: original MIPS .pdata 4092f564..4092f6e3. Semantic name remains unreviewed. */

void FUN_4092f564(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 *puVar3;
  undefined4 unaff_s2;
  undefined4 unaff_s3;
  undefined4 unaff_s4;
  undefined4 unaff_s5;
  
  iVar1 = mali_frame_builder_get_supersample_factor(param_2);
  if (iVar1 == 2) {
    iVar1 = 3;
    puVar3 = param_3;
    do {
      uVar2 = __fpmul(*puVar3,0x40000000);
      *puVar3 = uVar2;
      uVar2 = __fpmul(puVar3[1],0x40000000);
      iVar1 = iVar1 + -1;
      puVar3[1] = uVar2;
      puVar3 = puVar3 + 3;
    } while (iVar1 != 0);
  }
  uVar2 = mali_frame_builder_get_gp_job(param_2);
  iVar1 = mali_gp_job_add_vs_cmd(uVar2);
  if ((iVar1 == 0) && (iVar1 = mali_gp_job_add_vs_cmd(uVar2), iVar1 == 0)) {
    uVar2 = mali_frame_builder_get_gp_job(param_2);
    iVar1 = mali_gp_job_add_plbu_cmd(uVar2);
    if (iVar1 == 0) {
      uVar2 = mali_frame_builder_get_gp_job(param_2);
      iVar1 = FUN_4092eb08(param_1,param_2,param_3,uVar2,unaff_s5,unaff_s4,unaff_s3,unaff_s2,
                           unaff_s1,unaff_s0);
      if ((iVar1 == 0) && (iVar1 = mali_frame_builder_flush_gp(param_2,0,0), iVar1 == 0)) {
        uVar2 = mali_frame_builder_get_gp_job(param_2);
        iVar1 = mali_gp_job_add_vs_cmd(uVar2);
        if (iVar1 == 0) {
          uVar2 = mali_frame_builder_get_gp_job(param_2);
          mali_gp_job_add_plbu_cmd(uVar2);
        }
      }
    }
  }
  return;
}



/* 4092f6e4 FUN_4092f6e4 */

/* Boundary evidence: original MIPS .pdata 4092f6e4..4092f7c3. Semantic name remains unreviewed. */

int * FUN_4092f6e4(undefined4 param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar1 = FUN_409319b8();
  piVar2 = (int *)mali_sys_malloc(0x18);
  if (piVar2 != (int *)0x0) {
    mali_sys_memset(piVar2,0,0x18);
    uVar3 = mali_render_attachment_get_target(*(undefined4 *)(param_2 + 0xc),0,0);
    uVar4 = mali_frame_builder_get_supersample_factor(param_1);
    iVar5 = mali_surface_alloc_surface(uVar3,0,piVar1[7]);
    *piVar2 = iVar5;
    if (iVar5 == 0) {
      mali_sys_free();
    }
    else {
      iVar5 = mali_render_attachment_alloc(piVar2,1,1,uVar4,0);
      piVar2[3] = iVar5;
      if (iVar5 != 0) {
        return piVar2;
      }
      FUN_4092f410(piVar2);
    }
  }
  return (int *)0x0;
}



/* 4092f7c4 FUN_4092f7c4 */

/* Boundary evidence: original MIPS .pdata 4092f7c4..4092f80f. Semantic name remains unreviewed. */

void FUN_4092f7c4(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  uVar1 = mali_frame_builder_get_attachment(*(undefined4 *)(param_1 + 8),0);
  FUN_409271ac(param_1,1,uVar1,param_4);
  return;
}



/* 4092f810 FUN_4092f810 */

/* Boundary evidence: original MIPS .pdata 4092f810..4092f86f. Semantic name remains unreviewed. */

bool FUN_4092f810(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  
  if (*(int *)(param_2 + 0xc) == 0x30a0) {
    bVar1 = FUN_409281bc(param_1,param_2);
    iVar2 = CONCAT31(extraout_var,bVar1);
  }
  else {
    if (*(int *)(param_2 + 0xc) != 0x30a1) {
      return true;
    }
    bVar1 = FUN_40927354(param_1,param_2);
    iVar2 = CONCAT31(extraout_var_00,bVar1);
  }
  return iVar2 == 1;
}



/* 4092f870 FUN_4092f870 */

/* Boundary evidence: original MIPS .pdata 4092f870..4092f8df. Semantic name remains unreviewed. */

void FUN_4092f870(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  FUN_40935b30();
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar2 + 8) == 0x30a1) {
    piVar1 = FUN_409319b8();
    (**(code **)(piVar1[0xc] + 0xe8))(*(undefined4 *)(iVar2 + 0xc),param_2,param_3);
  }
  else if (*(int *)(iVar2 + 8) == 0x30a0) {
    FUN_40928460(iVar2,param_2,param_3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 4092f8e0 FUN_4092f8e0 */

/* Boundary evidence: original MIPS .pdata 4092f8e0..4092f92b. Semantic name remains unreviewed. */

void FUN_4092f8e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  FUN_40935b30();
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar2 + 8) == 0x30a1) {
    piVar1 = FUN_409319b8();
    (**(code **)(piVar1[0xc] + 0xe4))(*(undefined4 *)(iVar2 + 0xc),param_2,param_3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 4092f92c FUN_4092f92c */

/* Boundary evidence: original MIPS .pdata 4092f92c..4092f98f. Semantic name remains unreviewed. */

void FUN_4092f92c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  FUN_40935b30();
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar2 + 8) == 0x30a1) {
    piVar1 = FUN_409319b8();
    (**(code **)(piVar1[0xc] + 0xe0))(*(undefined4 *)(iVar2 + 0xc),param_2,param_3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 4092f990 FUN_4092f990 */

/* Boundary evidence: original MIPS .pdata 4092f990..4092fa47. Semantic name remains unreviewed. */

void FUN_4092f990(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  piVar1 = FUN_409319b8();
  iVar2 = param_1[1];
  if (param_2 == 0) {
    (**(code **)(iVar2 + 0x100))
              (piVar1[7],**(undefined4 **)(iVar2 + 0xb4),iVar2,*param_1,
               *(undefined4 *)(iVar2 + 0xac));
  }
  puVar3 = param_1;
  if (((*(uint *)(iVar2 + 0x10) & 1) != 0) && ((*(uint *)(iVar2 + 0x10) & 2) == 0)) {
    puVar3 = *(undefined4 **)(iVar2 + 0x6c);
    *(undefined4 **)(iVar2 + 0x6c) = param_1;
  }
  param_1[2] = 0;
  if ((puVar3 != (undefined4 *)0x0) && (param_2 == 0)) {
    mali_ds_consumer_release_connections(puVar3[4],0,1,0);
  }
  return;
}



/* 4092fa48 FUN_4092fa48 */

/* Boundary evidence: original MIPS .pdata 4092fa48..4092fa63. Semantic name remains unreviewed. */

void FUN_4092fa48(undefined4 *param_1)

{
  FUN_4092f990(param_1,0);
  return;
}



/* 4092fa64 FUN_4092fa64 */

/* Boundary evidence: original MIPS .pdata 4092fa64..4093005b. Semantic name remains unreviewed. */

void FUN_4092fa64(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined4 uVar8;
  uint in_stack_00000020;
  uint in_stack_00000024;
  undefined4 in_stack_00000028;
  uint in_stack_0000002c;
  uint in_stack_00000030;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint in_stack_00000040;
  uint in_stack_00000048;
  uint in_stack_0000004c;
  uint in_stack_00000050;
  uint in_stack_00000054;
  uint uStack00000058;
  undefined4 uStack0000005c;
  undefined4 uStack00000060;
  undefined4 uStack00000064;
  undefined4 uStack00000068;
  undefined4 uStack0000006c;
  undefined4 in_stack_00000070;
  undefined4 in_stack_00000074;
  undefined4 in_stack_00000078;
  undefined4 in_stack_0000007c;
  undefined4 in_stack_00000080;
  undefined4 in_stack_00000084;
  undefined4 in_stack_00000088;
  undefined4 in_stack_0000008c;
  undefined4 in_stack_00000090;
  undefined4 uStack00000098;
  undefined4 uStack0000009c;
  undefined4 uStack000000a0;
  undefined4 uStack000000a4;
  undefined4 uStack000000a8;
  undefined4 uStack000000ac;
  undefined4 uStack000000b0;
  undefined4 uStack000000b4;
  undefined4 uStack000000b8;
  undefined4 uStack000000bc;
  undefined4 uStack000000c0;
  int in_stack_00000100;
  undefined4 in_stack_00000104;
  
  FUN_40935a70();
  uStack00000058 = 0x5e6;
  uStack00000068 = 0xe4e;
  uStack0000006c = 1999;
  uStack00000064 = 0x39001000;
  uStack000000a4 = 0x39001000;
  uStack000000a8 = 0x55e;
  uStack000000ac = 0x7ce;
  uVar8 = *(undefined4 *)(param_2 + 8);
  uStack00000098 = 0x22805c6;
  uStack0000005c = 0xf1003c20;
  uStack00000060 = 0;
  uStack0000009c = 0xf1003c20;
  uStack000000a0 = 0;
  uStack000000b0 = 0x9e5;
  uStack000000b4 = 0xffe40404;
  uStack000000b8 = 0;
  uStack000000bc = 0x39001001;
  uStack000000c0 = 0x3e400039;
  uVar1 = mali_frame_builder_get_base_ctx(uVar8);
  puVar2 = (uint *)mali_mem_alloc(uVar1,0x18,0x40,1);
  if (puVar2 == (uint *)0x0) goto LAB_40930050;
  mali_frame_builder_add_frame_mem(uVar8,puVar2);
  mali_mem_write(puVar2,0,&stack0x00000058,0x18);
  mali_sys_memset(&stack0x00000018,0,0x40);
  in_stack_0000004c = in_stack_0000004c & 0xffffffbf;
  in_stack_0000003c = uStack00000058 & 0x1f ^ in_stack_0000003c & 0xffffffe0;
  if (puVar2[1] == 0) {
    uVar3 = mali_mem_mali_addr_get_full(puVar2,0);
  }
  else {
    uVar3 = *puVar2;
  }
  in_stack_00000028 = 0xffff0000;
  in_stack_0000003c = in_stack_0000003c & 0x3f ^ uVar3;
  in_stack_00000038 = in_stack_00000038 & 0xffff0fff ^ 0xf000;
  in_stack_00000040 = in_stack_00000040 & 0xfffffff8 ^ 1;
  in_stack_00000050 = in_stack_00000050 & 0xffff;
  in_stack_0000004c = (in_stack_0000004c & 0xffffffe0 ^ 1) & 0xffffff7f;
  uVar1 = mali_frame_builder_get_base_ctx(uVar8);
  puVar2 = (uint *)mali_mem_alloc(uVar1,0x44,0x40,1);
  if (puVar2 == (uint *)0x0) goto LAB_40930050;
  mali_frame_builder_add_frame_mem(uVar8,puVar2);
  puVar4 = (uint *)mali_mem_ptr_map_area(puVar2,0,0x44,0);
  if (puVar4 == (uint *)0x0) goto LAB_40930050;
  if (in_stack_00000100 == 0) {
    iVar5 = FUN_4092f0a0(puVar4,param_2);
    if (iVar5 != 0) {
      mali_mem_ptr_unmap_area(puVar2);
      goto LAB_40930050;
    }
    if (puVar2[1] != 0) goto LAB_4092fcc8;
LAB_4092fd64:
    uVar3 = mali_mem_mali_addr_get_full(puVar2,0);
LAB_4092fccc:
    puVar4[0x10] = uVar3;
  }
  else if (in_stack_00000100 == 1) {
    FUN_4092f1bc(puVar4,param_4,0,0,in_stack_00000104);
    if (puVar2[1] == 0) goto LAB_4092fd64;
LAB_4092fcc8:
    uVar3 = *puVar2;
    goto LAB_4092fccc;
  }
  mali_mem_ptr_unmap_area(puVar2);
  in_stack_0000004c = in_stack_0000004c & 0xf0003fff ^ 0x4000;
  in_stack_00000048 = in_stack_00000048 & 0xfffffff0;
  if (puVar2[1] == 0) {
    uVar3 = mali_mem_mali_addr_get_full(puVar2,0x40);
  }
  else {
    uVar3 = *puVar2 + 0x40;
  }
  in_stack_00000048 = in_stack_00000048 & 0xf ^ uVar3;
  in_stack_00000038 = in_stack_00000038 & 0xfffffff8 ^ 7;
  in_stack_0000004c = in_stack_0000004c & 0xffffffdf ^ 0x20;
  in_stack_00000020 =
       (((((((((((in_stack_00000020 & 0xfffffff8 ^ 2) & 0xfffffe3f ^ 0xc0) & 0xfffffdff ^ 0x200) &
               0xffffc3ff ^ 0x1800) & 0xffff3fc7 ^ 0x10) & 0xfff8ffff ^ 0x30000) & 0xfff7ffff ^
           0x80000) & 0xff8fffff ^ 0x300000) & 0xef7fffff ^ 0x10000000) & 0xdfffffff ^ 0x20000000) &
        0xbfffffff ^ 0x40000000) & 0x7fffffff ^ 0x80000000;
  in_stack_00000024 = (in_stack_00000024 & 0xfffffff1 ^ 0xe) & 0xfffffffe;
  in_stack_0000002c = (in_stack_0000002c & 0xfffffff8 ^ 7) & 0xfffff007;
  in_stack_00000030 = (in_stack_00000030 & 0xfffffff8 ^ 7) & 0xfffff007;
  iVar5 = FUN_4092efb0(param_1,uVar8);
  if (iVar5 == 0) {
    piVar7 = (int *)param_1[2];
    if (piVar7[1] == 0) {
      uVar3 = mali_mem_mali_addr_get_full(piVar7,*param_1);
    }
    else {
      uVar3 = *piVar7 + *param_1;
    }
    in_stack_00000054 = in_stack_00000054 & 0xf ^ uVar3;
    in_stack_0000004c = in_stack_0000004c & 0xffffffe0 ^ 2;
    iVar5 = mali_render_attachment_get_target(param_4,in_stack_00000104,0);
    uVar6 = (uint)*(ushort *)(iVar5 + 0xc);
    uVar3 = FUN_4092ea4c((int *)(iVar5 + 0x14));
    if ((uVar3 & 0xfffffff8) != 0) {
      uVar3 = FUN_4092ea4c((int *)(iVar5 + 0x14));
      uVar6 = (uint)*(ushort *)(iVar5 + 0x10) / (uVar3 >> 3);
      if (uVar3 >> 3 == 0) {
        trap(0x1c00);
      }
    }
    in_stack_00000070 = __litofp(uVar6);
    in_stack_00000074 = 0;
    in_stack_00000078 = 0;
    in_stack_0000007c = 0;
    in_stack_00000080 = 0;
    in_stack_00000084 = 0;
    in_stack_00000088 = 0;
    in_stack_0000008c = __litofp(*(undefined2 *)(iVar5 + 0xe));
    in_stack_00000090 = 0;
    iVar5 = FUN_4092ee9c(param_1,uVar8,&stack0x00000018);
    if (iVar5 == 0) {
      param_1[5] = 0;
      FUN_4092f564(param_1,uVar8,&stack0x00000070);
    }
  }
LAB_40930050:
                    /* WARNING: Subroutine does not return */
  FUN_40935aa8(200);
}



/* 4093005c FUN_4093005c */

/* Boundary evidence: original MIPS .pdata 4093005c..4093010b. Semantic name remains unreviewed. */

undefined4 FUN_4093005c(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*(int *)(*(int *)(param_3 + 0xc) + 8) == 0x30a1) {
    if (*(int *)(param_1 + 200) == 0) {
      uVar2 = 1;
    }
    else {
      iVar1 = FUN_4092e690(param_1,1,0,0);
      if ((iVar1 != 1) || (iVar1 = FUN_4092f7c4(param_1,1,param_2,param_3), iVar1 != 1)) {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



/* 4093010c FUN_4093010c */

/* Boundary evidence: original MIPS .pdata 4093010c..409303ff. Semantic name remains unreviewed. */

void FUN_4093010c(int param_1,uint param_2,uint param_3,int *param_4,undefined4 param_5,
                 undefined4 param_6,int param_7,int param_8,int param_9)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  
  FUN_40935a70();
  param_8 = 0;
  param_9 = 0;
  iVar5 = 0;
  param_7 = 0;
  if (param_4[3] == 0x30a0) {
    iVar6 = param_4[1];
  }
  else {
    if (param_4[3] != 0x30a1) goto LAB_409303f4;
    iVar6 = *param_4;
  }
  if (((iVar6 == 0) || (param_2 == 0)) || (param_3 == 0)) goto LAB_409303f4;
  mali_frame_builder_wait(*(undefined4 *)(param_1 + 8));
  while ((*(int *)(param_1 + 0x1c) == 1 || (*(int *)(param_1 + 0x30) == 1))) {
    mali_sys_yield();
  }
  piVar7 = (int *)(param_1 + 0x24);
  iVar8 = 4;
  do {
    if (*piVar7 != 0) {
      mali_ds_consumer_release_connections(*piVar7,0,1,0x7fffffff);
    }
    *(undefined4 *)(param_1 + 0x6c) = 0;
    iVar8 = iVar8 + -1;
    piVar7 = piVar7 + 5;
  } while (iVar8 != 0);
  if (((*(uint *)(param_1 + 0x10) & 1) == 0) ||
     (iVar8 = param_8, iVar2 = param_9, (*(uint *)(param_1 + 0x10) & 2) != 0)) {
    iVar8 = mali_frame_builder_get_attachment(*(undefined4 *)(param_1 + 8),0);
    uVar1 = mali_frame_builder_get_supersample_factor(*(undefined4 *)(param_1 + 8));
    iVar2 = mali_render_attachment_get_target(iVar8,0,0);
    param_7 = mali_surface_alloc(param_2 & 0xffff,param_3 & 0xffff,0,iVar2 + 0x14);
    iVar5 = mali_render_attachment_alloc(&param_7,1,1,uVar1);
    iVar3 = param_7;
    if (iVar5 != 0) {
      if (param_7 != 0) goto LAB_409302b8;
LAB_4093028c:
      mali_render_attachment_free(iVar5);
      iVar3 = param_7;
    }
  }
  else {
LAB_409302b8:
    iVar3 = FUN_4092f92c(iVar6,param_2,param_3);
    if (iVar3 == 0) {
      iVar3 = param_7;
      if (iVar5 != 0) goto LAB_4093028c;
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0x108) + 0x70) = 1;
      if (iVar5 != 0) {
        *(int *)(param_1 + 100) = iVar5;
      }
      if (((*(uint *)(param_1 + 0x10) & 1) == 0) && ((*(uint *)(param_1 + 0x10) & 2) == 0)) {
        uVar1 = *(undefined4 *)(param_1 + 100);
      }
      else {
        uVar1 = *(undefined4 *)(param_1 + 0x68);
      }
      mali_frame_builder_set_attachment(*(undefined4 *)(param_1 + 8),0,uVar1);
      *(uint *)(param_1 + 0xbc) = param_2;
      *(uint *)(param_1 + 0xc0) = param_3;
      uVar1 = mali_frame_builder_get_attachment(*(undefined4 *)(param_1 + 8),0);
      uVar4 = mali_render_attachment_get_target(uVar1,0,0);
      *(undefined4 *)(param_1 + 0x14) = uVar4;
      *(int *)(param_1 + 0x18) = param_1;
      *(undefined2 *)(param_1 + 0x20) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      uVar1 = mali_render_attachment_get_target(uVar1,1,0);
      *(undefined2 *)(param_1 + 0x72) = 2;
      *(undefined4 *)(param_1 + 0x28) = uVar1;
      *(int *)(param_1 + 0x2c) = param_1;
      *(undefined2 *)(param_1 + 0x34) = 1;
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined2 *)(param_1 + 0x70) = 0;
      if ((*(uint *)(param_1 + 0x10) & 2) != 0) {
        mali_frame_builder_set_attachment
                  (*(undefined4 *)(param_1 + 8),0,*(undefined4 *)(param_1 + 100));
      }
      FUN_4092f870(iVar6,param_2,param_3);
      if ((((*(uint *)(param_1 + 0x10) & 1) != 0) && ((*(uint *)(param_1 + 0x10) & 2) == 0)) ||
         (iVar8 == 0)) goto LAB_409303f4;
      mali_render_attachment_free(iVar8);
      iVar3 = iVar2;
    }
  }
  if (iVar3 != 0) {
    FUN_4092e9dc(iVar3);
  }
LAB_409303f4:
                    /* WARNING: Subroutine does not return */
  FUN_40935aa8(0x28);
}



/* 40930400 FUN_40930400 */

/* Boundary evidence: original MIPS .pdata 40930400..40930447. Semantic name remains unreviewed. */

void FUN_40930400(int *param_1)

{
  int iVar1;
  
  iVar1 = mali_ds_connect_give_direct_ownership_and_flush
                    (param_1[4],*(undefined4 *)(*param_1 + 0x38),0);
  if (iVar1 != 0) {
    FUN_4092f990(param_1,1);
  }
  return;
}



/* 40930448 FUN_40930448 */

/* Boundary evidence: original MIPS .pdata 40930448..40930667. Semantic name remains unreviewed. */

undefined4 FUN_40930448(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 auStack_40 [3];
  undefined4 local_34 [3];
  
  uVar5 = *(undefined4 *)(param_1 + 8);
  FUN_4092e648(uVar5,auStack_40);
  piVar1 = FUN_4092f6e4(uVar5,(int)auStack_40);
  if (piVar1 != (int *)0x0) {
    FUN_4092e5ec(uVar5,(int)piVar1);
    iVar2 = mali_frame_builder_use(uVar5);
    if (iVar2 == 0) {
      iVar2 = FUN_4092e548(uVar5);
      if (iVar2 == 0) {
        mali_frame_builder_reset(uVar5);
        uVar4 = 0;
        puVar6 = local_34;
        do {
          mali_frame_builder_set_attachment(uVar5,uVar4,*puVar6);
          uVar4 = uVar4 + 1;
          puVar6 = puVar6 + 1;
        } while (uVar4 < 3);
        *(int *)(param_1 + 0x74) = 0;
        *(undefined4 *)(param_1 + 0x78) = 0;
        *(undefined4 *)(param_1 + 0x7c) = 0;
        *(undefined4 *)(param_1 + 0x80) = 0;
        *(undefined4 *)(param_1 + 0x84) = 0;
        *(undefined4 *)(param_1 + 0x88) = 0;
        *(undefined4 *)(param_1 + 0x8c) = 0;
        *(undefined4 *)(param_1 + 0x90) = 0;
        *(undefined4 *)(param_1 + 0x94) = 0;
        *(undefined4 *)(param_1 + 0x98) = 0;
        iVar2 = mali_frame_builder_write_lock(uVar5);
        if (iVar2 == 0) {
          iVar2 = mali_frame_builder_add_callback(uVar5,FUN_4092f410,piVar1);
          if (iVar2 != 0) {
            mali_frame_builder_write_unlock(uVar5);
            FUN_4092f410(piVar1);
            mali_frame_builder_reset(uVar5);
            return 0;
          }
          iVar2 = FUN_4092fa64((int *)(param_1 + 0x74),param_1,0,piVar1[3]);
          mali_frame_builder_write_unlock(uVar5);
          iVar3 = mali_frame_builder_flush(*(undefined4 *)(param_1 + 8),0,0);
          if (iVar3 != 0) {
            iVar2 = -1;
          }
          if (iVar2 != 0) {
            return 0;
          }
          return 1;
        }
      }
      else {
        uVar4 = 0;
        puVar6 = local_34;
        do {
          mali_frame_builder_set_attachment(uVar5,uVar4,*puVar6);
          uVar4 = uVar4 + 1;
          puVar6 = puVar6 + 1;
        } while (uVar4 < 3);
      }
    }
    else {
      uVar4 = 0;
      puVar6 = local_34;
      do {
        mali_frame_builder_set_attachment(uVar5,uVar4,*puVar6);
        uVar4 = uVar4 + 1;
        puVar6 = puVar6 + 1;
      } while (uVar4 < 3);
    }
    FUN_4092f410(piVar1);
  }
  return 0;
}



/* 40930668 FUN_40930668 */

/* Boundary evidence: original MIPS .pdata 40930668..4093070f. Semantic name remains unreviewed. */

undefined4 FUN_40930668(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  iVar1 = mali_frame_builder_use(*(undefined4 *)(param_1 + 8));
  if ((iVar1 == 0) && (iVar1 = FUN_4092fa64((int *)(param_1 + 0x74),param_1,0,param_2), iVar1 == 0))
  {
    return 1;
  }
  return 0;
}



/* 40930710 FUN_40930710 */

/* Boundary evidence: original MIPS .pdata 40930710..409307cf. Semantic name remains unreviewed. */

void FUN_40930710(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iStack00000010;
  undefined4 *puStack00000014;
  
  FUN_40935ae0();
  iStack00000010 = param_3;
  puStack00000014 = param_4;
  iVar1 = FUN_4092e690(param_1,1,0,0);
  if (iVar1 == 1) {
    uVar2 = mali_frame_builder_get_attachment(*(undefined4 *)(param_1 + 8),0);
    uVar2 = mali_render_attachment_get_target(uVar2,0,0);
    iStack00000010 = param_2;
    (**(code **)(param_1 + 0x104))
              (*(undefined4 *)(*(int *)(param_3 + 8) + 0x1c),*(undefined4 *)*param_4,param_1,uVar2);
    FUN_40930448(param_1);
    FUN_4092f810(param_1,param_3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 409307d0 FUN_409307d0 */

/* Boundary evidence: original MIPS .pdata 409307d0..4093095b. Semantic name remains unreviewed. */

undefined4 FUN_409307d0(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined4 uVar5;
  int unaff_s5;
  int *piVar6;
  uint in_stack_ffffffd8;
  uint in_stack_ffffffdc;
  
  uVar5 = 0;
  if ((param_1[4] & 2) != 0) {
    uVar2 = mali_render_attachment_get_target(param_1[0x1a],0,0);
    uVar5 = mali_frame_builder_get_attachment(param_1[2],0);
    mali_frame_builder_set_attachment(param_1[2],0,param_1[0x1a]);
    param_1[(*(ushort *)(param_1 + 0x1c) + 1) * 5] = uVar2;
    mali_frame_builder_use(param_1[2]);
  }
  uVar2 = mali_frame_builder_get_attachment(param_1[2],0);
  piVar6 = param_2;
  uVar3 = FUN_4092e690((int)param_1,0,1,FUN_40930400);
  if ((param_1[0x3a] == 0x3094) && (iVar4 = FUN_40930668((int)param_1,uVar2), iVar4 == 0)) {
    uVar3 = 0;
  }
  if ((param_1[4] & 2) != 0) {
    mali_frame_builder_set_attachment(param_1[2],0,uVar5);
  }
  FUN_40928940(param_1,(int *)&stack0xffffffdc,(int *)&stack0xffffffd8);
  if (((in_stack_ffffffdc != param_1[0x2f]) || (in_stack_ffffffd8 != param_1[0x30])) &&
     (iVar4 = FUN_4093010c((int)param_1,in_stack_ffffffdc,in_stack_ffffffd8,param_2,piVar6,param_3,
                           in_stack_ffffffd8,in_stack_ffffffdc,unaff_s5), iVar4 == 0)) {
    uVar3 = 0;
  }
  bVar1 = FUN_4092f810((int)param_1,(int)param_2);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar3 = 0;
  }
  return uVar3;
}



/* 40930978 FUN_40930978 */

/* Boundary evidence: original MIPS .pdata 40930978..409309df. Semantic name remains unreviewed. */

undefined * FUN_40930978(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  if (param_1 == 0) {
    puVar1 = (undefined *)0x0;
  }
  else {
    puVar1 = (undefined *)FUN_40927d6c(param_2,param_1);
    if ((puVar1 == (undefined *)0x0) &&
       (puVar1 = (undefined *)FUN_40927210(param_2,param_1), puVar1 == (undefined *)0x0)) {
      puVar1 = FUN_4092e464(param_1);
    }
  }
  return puVar1;
}



/* 409309e0 FUN_409309e0 */

/* Boundary evidence: original MIPS .pdata 409309e0..40930a73. Semantic name remains unreviewed. */

undefined4 FUN_409309e0(undefined4 *param_1)

{
  int *piVar1;
  int local_10 [2];
  
  FUN_4092c808(param_1,local_10);
  if (local_10[0] == 0x30a0) {
    if (param_1[7] == 0) {
      return 0;
    }
    FUN_40927fb4((int)param_1);
  }
  else if (local_10[0] == 0x30a1) {
    if (param_1[6] == 0) {
      return 0;
    }
    piVar1 = FUN_409319b8();
    (**(code **)(piVar1[0xc] + 0xf4))(param_1[6]);
  }
  return 1;
}



/* 40930a74 FUN_40930a74 */

/* Boundary evidence: original MIPS .pdata 40930a74..40930c13. Semantic name remains unreviewed. */

void FUN_40930a74(uint param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  FUN_40935ae0();
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_4 != 0) {
      *(undefined4 *)(param_4 + 0x10) = 0x3008;
    }
    goto LAB_40930c0c;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) == 0) {
LAB_40930ad8:
    if (param_4 == 0) goto LAB_40930c0c;
    uVar3 = 0x3001;
  }
  else {
    iVar2 = FUN_4092bc84(param_2,param_1,param_4);
    if (iVar2 == 0) goto LAB_40930c0c;
    if ((*(uint *)(iVar1 + 0x20) & 2) != 0) goto LAB_40930ad8;
    if (param_3 != 0x3084) {
      if (param_4 == 0) goto LAB_40930c0c;
      uVar3 = 0x300c;
LAB_40930b30:
      *(undefined4 *)(param_4 + 0x10) = uVar3;
      goto LAB_40930c0c;
    }
    if ((*(uint *)(iVar2 + 0xc) & 1) == 0) {
      if (param_4 == 0) goto LAB_40930c0c;
      uVar3 = 0x300d;
    }
    else {
      uVar4 = *(uint *)(*(int *)(iVar2 + 0xb8) + 0x5c);
      if (((uVar4 & 1) == 0) && ((uVar4 & 4) == 0)) {
        if (param_4 != 0) {
          *(undefined4 *)(param_4 + 0x10) = 0x300d;
        }
        goto LAB_40930c0c;
      }
      if (*(int *)(iVar2 + 0xf0) != 0x305c) {
        if (*(int *)(iVar2 + 0xfc) == 0) {
          if (param_4 == 0) goto LAB_40930c0c;
          uVar3 = 0x3002;
        }
        else {
          if (*(int *)(param_4 + 4) != 0) {
            iVar1 = *(int *)(*(int *)(param_4 + 4) + 0xc);
            (**(code **)(*(int *)(iVar1 + 0x18) * 0x4c + *(int *)(*(int *)(param_4 + 8) + 0x30) + -4
                        ))(*(undefined4 *)(iVar1 + 0xc));
            *(undefined4 *)(iVar2 + 0xfc) = 0;
            goto LAB_40930c0c;
          }
          uVar3 = 0x3006;
        }
        goto LAB_40930b30;
      }
      if (param_4 == 0) goto LAB_40930c0c;
      uVar3 = 0x3009;
    }
  }
  *(undefined4 *)(param_4 + 0x10) = uVar3;
LAB_40930c0c:
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x10);
}



/* 40930c14 FUN_40930c14 */

/* Boundary evidence: original MIPS .pdata 40930c14..40930d17. Semantic name remains unreviewed. */

undefined4 FUN_40930c14(uint param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_3 == (int *)0x0) {
      return 0;
    }
    param_3[4] = 0x3008;
    return 0;
  }
  if (((*(uint *)(iVar1 + 0x20) & 1) == 0) || ((*(uint *)(iVar1 + 0x20) & 2) != 0)) {
    if (param_3 == (int *)0x0) {
      return 0;
    }
    param_3[4] = 0x3001;
    return 0;
  }
  if (param_3[3] == 0x30a0) {
    iVar1 = param_3[1];
  }
  else {
    if (param_3[3] != 0x30a1) goto LAB_40930cf8;
    iVar1 = *param_3;
  }
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) != 0)) {
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 0xb8);
    iVar2 = *(int *)(iVar3 + 0x4c);
    if ((param_2 < iVar2) || (iVar2 = *(int *)(iVar3 + 0x48), iVar2 < param_2)) {
      param_2 = iVar2;
    }
    *(int *)(*(int *)(iVar1 + 4) + 0xac) = param_2;
    return 1;
  }
LAB_40930cf8:
  param_3[4] = 0x3006;
  return 0;
}



/* 40930d18 FUN_40930d18 */

/* Boundary evidence: original MIPS .pdata 40930d18..40930ed3. Semantic name remains unreviewed. */

void FUN_40930d18(uint param_1,uint param_2,HANDLE param_3,undefined4 *param_4,undefined4 param_5,
                 undefined4 param_6,int param_7)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  FUN_40935ae0();
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_4 != (undefined4 *)0x0) {
      param_4[4] = 0x3008;
    }
    goto LAB_40930ec8;
  }
  if (((*(uint *)(iVar1 + 0x20) & 1) == 0) || ((*(uint *)(iVar1 + 0x20) & 2) != 0)) {
    if (param_4 != (undefined4 *)0x0) {
      param_4[4] = 0x3001;
    }
    goto LAB_40930ec8;
  }
  iVar1 = GetObjectW(param_3,0x54,&stack0x00000020);
  if (iVar1 == 0) {
    if (param_4 == (undefined4 *)0x0) goto LAB_40930ec8;
    uVar5 = 0x300a;
  }
  else {
    iVar1 = FUN_4092bc84(param_2,param_1,(int)param_4);
    if (iVar1 == 0) goto LAB_40930ec8;
    puVar2 = (undefined4 *)FUN_4092c808(param_4,&param_7);
    if ((puVar2 != (undefined4 *)0x0) && (puVar2[3] != 0)) {
      if (*(int *)(puVar2[3] + 0x20) == 1) {
        if (param_4 == (undefined4 *)0x0) goto LAB_40930ec8;
        uVar5 = 0x300e;
      }
      else {
        if (puVar2[1] == iVar1) {
          iVar3 = FUN_40928ba4(param_3,iVar1);
          if (iVar3 == 0) {
            if (param_4 == (undefined4 *)0x0) goto LAB_40930ec8;
            uVar5 = 0x3009;
          }
          else {
            if (param_7 == 0x30a1) {
              piVar4 = FUN_409319b8();
              (**(code **)(piVar4[0xc] + 0xf0))(param_4[6]);
            }
            iVar1 = FUN_40930710(iVar1,param_3,(int)param_4,puVar2);
            if ((iVar1 != 0) || (param_4 == (undefined4 *)0x0)) goto LAB_40930ec8;
            uVar5 = 0x3003;
          }
          goto LAB_40930ec0;
        }
        if (param_4 == (undefined4 *)0x0) goto LAB_40930ec8;
        uVar5 = 0x300d;
      }
      param_4[4] = uVar5;
      goto LAB_40930ec8;
    }
    if (param_4 == (undefined4 *)0x0) goto LAB_40930ec8;
    uVar5 = 0x3006;
  }
LAB_40930ec0:
  param_4[4] = uVar5;
LAB_40930ec8:
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x78);
}



/* 40930ed4 FUN_40930ed4 */

/* Boundary evidence: original MIPS .pdata 40930ed4..409310a3. Semantic name remains unreviewed. */

undefined4 FUN_40930ed4(uint param_1,uint param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int local_20 [2];
  
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_3 == (int *)0x0) {
      return 0;
    }
    param_3[4] = 0x3008;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
    puVar2 = (undefined4 *)FUN_4092bc84(param_2,param_1,(int)param_3);
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
      iVar1 = FUN_4092c808(param_3,local_20);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) != 0)) {
        if (*(int *)(*(int *)(iVar1 + 0xc) + 0x20) == 1) {
          if (param_3 == (int *)0x0) {
            return 0;
          }
          iVar1 = 0x300e;
        }
        else {
          if (*(undefined4 **)(iVar1 + 4) == puVar2) {
            if (puVar2[3] == 1) {
              return 1;
            }
            if (puVar2[3] == 2) {
              return 1;
            }
            if (puVar2[0x39] == 0x3085) {
              return 1;
            }
            if (local_20[0] == 0x30a0) {
              FUN_40928000((int)param_3);
            }
            else if (local_20[0] == 0x30a1) {
              piVar3 = FUN_409319b8();
              (**(code **)(piVar3[0xc] + 0xf0))(param_3[6]);
            }
            iVar1 = FUN_409307d0(puVar2,param_3,iVar1);
            if (iVar1 != 0) {
              return 1;
            }
            if (param_3 == (int *)0x0) {
              return 0;
            }
            iVar1 = 0x3003;
            goto LAB_4093107c;
          }
          if (param_3 == (int *)0x0) {
            return 0;
          }
          iVar1 = 0x300d;
        }
        param_3[4] = iVar1;
        return 0;
      }
      if (param_3 == (int *)0x0) {
        return 0;
      }
      iVar1 = 0x3006;
LAB_4093107c:
      param_3[4] = iVar1;
      return 0;
    }
  }
  if (param_3 != (int *)0x0) {
    param_3[4] = 0x3001;
  }
  return 0;
}



/* 409310a4 FUN_409310a4 */

/* Boundary evidence: original MIPS .pdata 409310a4..409311db. Semantic name remains unreviewed. */

undefined4 FUN_409310a4(int param_1,int *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  
  if (param_2[3] == 0x30a0) {
    iVar2 = param_2[1];
  }
  else {
    if (param_2[3] != 0x30a1) {
      return 1;
    }
    iVar2 = *param_2;
  }
  if (((iVar2 == 0) || (*(int *)(iVar2 + 0xc) == 0)) || (*(int *)(*(int *)(iVar2 + 4) + 0xc) != 2))
  {
    return 1;
  }
  if (param_1 == 0x305b) {
    iVar2 = FUN_40930448(*(int *)(iVar2 + 4));
    if ((iVar2 != 0) &&
       (((param_2[3] != 0x30a1 || (iVar2 = *param_2, iVar2 == 0)) ||
        ((*(int *)(iVar2 + 0xc) == 0 ||
         (bVar1 = FUN_40927354(*(int *)(iVar2 + 4),(int)param_2), CONCAT31(extraout_var,bVar1) != 0)
         ))))) {
      if (param_2[3] != 0x30a0) {
        return 1;
      }
      iVar2 = param_2[1];
      if (iVar2 == 0) {
        return 1;
      }
      if (*(int *)(iVar2 + 0xc) == 0) {
        return 1;
      }
      bVar1 = FUN_409281bc(*(int *)(iVar2 + 4),(int)param_2);
      if (CONCAT31(extraout_var_00,bVar1) != 0) {
        return 1;
      }
    }
    iVar2 = 0x3003;
  }
  else {
    iVar2 = 0x300c;
  }
  param_2[4] = iVar2;
  return 0;
}



/* 409311dc FUN_409311dc */

/* Boundary evidence: original MIPS .pdata 409311dc..4093128b. Semantic name remains unreviewed. */

void FUN_409311dc(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_40935b30();
  puVar1 = (undefined4 *)FUN_4092c808(param_1,(undefined4 *)&stack0x00000018);
  if ((((puVar1 != (undefined4 *)0x0) && (puVar1[3] != 0)) && (*(int *)(puVar1[3] + 0xc) != 0)) &&
     (((iVar2 = FUN_409309e0(param_1), iVar2 == 1 && (iVar2 = puVar1[1], *(int *)(iVar2 + 0xc) == 2)
       ) && ((iVar2 = FUN_40930710(iVar2,*(undefined4 *)(iVar2 + 4),(int)param_1,puVar1), iVar2 == 0
             && (param_1 != (undefined4 *)0x0)))))) {
    param_1[4] = 0x3003;
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x20);
}



/* 4093128c FUN_4093128c */

/* Boundary evidence: original MIPS .pdata 4093128c..4093141f. Semantic name remains unreviewed. */

char * FUN_4093128c(uint param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  piVar1 = FUN_409319b8();
  iVar2 = FUN_4092bb88(param_1);
  if (iVar2 == 0) {
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x3008;
    }
  }
  else if (((*(uint *)(iVar2 + 0x20) & 1) == 0) || ((*(uint *)(iVar2 + 0x20) & 2) != 0)) {
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x3001;
    }
  }
  else {
    if (param_2 == 0x3053) {
      return "ARM";
    }
    if (param_2 == 0x3054) {
      return "1.4 WindowsCE-r1p1-05rel0";
    }
    if (param_2 == 0x3055) {
      uVar3 = *(uint *)(piVar1[0xc] + 0x10c);
      if ((uVar3 & 5) == 5) {
        return 
        "EGL_KHR_image EGL_KHR_image_base EGL_KHR_image_pixmap EGL_KHR_vg_parent_image EGL_KHR_gl_texture_2D_image EGL_KHR_gl_texture_cubemap_image EGL_KHR_gl_renderbuffer_image "
        ;
      }
      if ((uVar3 & 1) == 0) {
        if ((uVar3 & 4) != 0) {
          return 
          "EGL_KHR_image EGL_KHR_image_base EGL_KHR_image_pixmap EGL_KHR_vg_parent_image EGL_KHR_gl_texture_2D_image EGL_KHR_gl_texture_cubemap_image EGL_KHR_gl_renderbuffer_image "
          ;
        }
        if ((uVar3 & 2) == 0) {
          return "";
        }
      }
      return 
      "EGL_KHR_image EGL_KHR_image_base EGL_KHR_image_pixmap EGL_KHR_vg_parent_image EGL_KHR_gl_texture_2D_image "
      ;
    }
    if (param_2 == 0x308d) {
      return "OpenGL_ES OpenVG";
    }
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x300c;
    }
  }
  return (char *)0x0;
}



/* 40931420 FUN_40931420 */

/* Boundary evidence: original MIPS .pdata 40931420..409314af. Semantic name remains unreviewed. */

undefined4 FUN_40931420(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1[7] == 0) {
    uVar2 = 1;
  }
  else {
    iVar3 = param_1[3];
    iVar1 = FUN_40932150(0x30a0,param_1);
    if (iVar1 == 1) {
      uVar2 = FUN_409311dc(param_1);
      iVar1 = FUN_40932150(iVar3,param_1);
      if (iVar1 == 1) {
        return uVar2;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 409314b0 FUN_409314b0 */

/* Boundary evidence: original MIPS .pdata 409314b0..40931633. Semantic name remains unreviewed. */

void FUN_409314b0(uint param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  FUN_40935ae0();
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_4 != (int *)0x0) {
      param_4[4] = 0x3008;
    }
    goto LAB_40931628;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) == 0) {
LAB_40931514:
    if (param_4 == (int *)0x0) goto LAB_40931628;
    iVar1 = 0x3001;
LAB_40931520:
    param_4[4] = iVar1;
  }
  else {
    iVar2 = FUN_4092bc84(param_2,param_1,(int)param_4);
    if (iVar2 == 0) goto LAB_40931628;
    if ((*(uint *)(iVar1 + 0x20) & 2) != 0) goto LAB_40931514;
    if (param_3 == 0x3084) {
      if (*(int *)(iVar2 + 0xfc) != 1) {
        if ((*(uint *)(iVar2 + 0xc) & 1) == 0) {
          if (param_4 == (int *)0x0) goto LAB_40931628;
          iVar1 = 0x300d;
        }
        else {
          uVar3 = *(uint *)(*(int *)(iVar2 + 0xb8) + 0x5c);
          if (((uVar3 & 1) == 0) && ((uVar3 & 4) == 0)) {
            if (param_4 != (int *)0x0) {
              param_4[4] = 0x300d;
            }
            goto LAB_40931628;
          }
          if (*(int *)(iVar2 + 0xf0) != 0x305c) {
            uVar3 = FUN_409323dc(param_4);
            if (uVar3 != 0) {
              FUN_4092804c(iVar2,(int)param_4);
            }
            goto LAB_40931628;
          }
          if (param_4 == (int *)0x0) goto LAB_40931628;
          iVar1 = 0x3009;
        }
        goto LAB_40931520;
      }
      if (param_4 == (int *)0x0) goto LAB_40931628;
      iVar1 = 0x3002;
    }
    else {
      if (param_4 == (int *)0x0) goto LAB_40931628;
      iVar1 = 0x300c;
    }
    param_4[4] = iVar1;
  }
LAB_40931628:
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x10);
}



/* 40931634 FUN_40931634 */

/* Boundary evidence: original MIPS .pdata 40931634..409317df. Semantic name remains unreviewed. */

void FUN_40931634(void)

{
  int *piVar1;
  int iVar2;
  undefined4 local_18 [2];
  
  local_18[0] = 0;
  if (DAT_40938af0 != (int *)0x0) {
    piVar1 = DAT_40938af0;
    if (*DAT_40938af0 != 0) {
      __mali_named_list_free(*DAT_40938af0,0);
      piVar1 = DAT_40938af0;
      *DAT_40938af0 = 0;
    }
    iVar2 = piVar1[2];
    if (iVar2 != 0) {
      while (piVar1 = (int *)__mali_named_list_iterate_begin(iVar2,local_18), piVar1 != (int *)0x0)
      {
        if (piVar1[1] != 0) {
          mali_sys_free();
        }
        if (*piVar1 != 0) {
          mali_sys_free();
        }
        __mali_named_list_remove(DAT_40938af0[2],piVar1[5]);
        mali_sys_free(piVar1);
        iVar2 = DAT_40938af0[2];
      }
      __mali_named_list_free(DAT_40938af0[2],0);
      piVar1 = DAT_40938af0;
      DAT_40938af0[2] = 0;
    }
    if (piVar1[5] != 0) {
      mali_sys_lock_try_lock(piVar1[5]);
      mali_sys_lock_unlock(DAT_40938af0[5]);
      mali_sys_lock_destroy(DAT_40938af0[5]);
      piVar1 = DAT_40938af0;
      DAT_40938af0[5] = 0;
    }
    if (piVar1[6] != 0) {
      mali_sys_mutex_try_lock(piVar1[6]);
      mali_sys_mutex_unlock(DAT_40938af0[6]);
      mali_sys_mutex_destroy(DAT_40938af0[6]);
      piVar1 = DAT_40938af0;
      DAT_40938af0[6] = 0;
    }
    if (piVar1[0xc] != 0) {
      FUN_40927c98((int)piVar1);
      piVar1 = DAT_40938af0;
    }
    if ((undefined4 *)piVar1[0xc] != (undefined4 *)0x0) {
      FUN_4092626c((undefined4 *)piVar1[0xc]);
      mali_sys_free(DAT_40938af0[0xc]);
      piVar1 = DAT_40938af0;
    }
    if (piVar1[0x12] != 0) {
      __mali_named_list_free(piVar1[0x12],0);
      piVar1 = DAT_40938af0;
    }
    mali_sys_free(piVar1);
    DAT_40938af0 = (int *)0x0;
  }
  return;
}



/* 409317e0 FUN_409317e0 */

/* Boundary evidence: original MIPS .pdata 409317e0..409318f3. Semantic name remains unreviewed. */

void FUN_409317e0(void)

{
  int iVar1;
  
  iVar1 = DAT_40938af0;
  if ((*(int *)(DAT_40938af0 + 0x34) != 0) && (*(int *)(DAT_40938af0 + 0x30) != 0)) {
    (**(code **)(*(int *)(DAT_40938af0 + 0x30) + 0xd4))();
    *(undefined4 *)(DAT_40938af0 + 0x34) = 0;
  }
  if ((*(uint *)(iVar1 + 0x2c) & 8) != 0) {
    *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) & 0xfffffff7;
  }
  if ((*(uint *)(iVar1 + 0x2c) & 4) != 0) {
    mali_gp_close(*(undefined4 *)(iVar1 + 0x1c));
    *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) & 0xfffffffb;
  }
  if ((*(uint *)(iVar1 + 0x2c) & 2) != 0) {
    mali_pp_close(*(undefined4 *)(iVar1 + 0x1c));
    *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) & 0xfffffffd;
  }
  if ((*(uint *)(iVar1 + 0x2c) & 1) != 0) {
    mali_mem_close(*(undefined4 *)(iVar1 + 0x1c));
    *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) & 0xfffffffe;
  }
  if (*(int *)(iVar1 + 0x1c) != 0) {
    mali_base_context_destroy();
    *(undefined4 *)(iVar1 + 0x1c) = 0;
  }
  return;
}



/* 409318f4 FUN_409318f4 */

/* Boundary evidence: original MIPS .pdata 409318f4..4093198b. Semantic name remains unreviewed. */

void FUN_409318f4(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = DAT_40938af0;
  *DAT_40938af0 = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[0xb] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xd] = 0;
  iVar2 = mali_sys_config_string_get_bool("MALI_NEVERBLIT",0);
  if (iVar2 != 0) {
    DAT_40938af0[9] = 1;
  }
  iVar2 = mali_sys_config_string_get_bool("MALI_FLIP_PIXMAP",0);
  if (iVar2 != 0) {
    DAT_40938af0[10] = 1;
  }
  return;
}



/* 409319b8 FUN_409319b8 */

/* Boundary evidence: original MIPS .pdata 409319b8..40931aff. Semantic name remains unreviewed. */

int * FUN_409319b8(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = mali_sys_mutex_auto_init(&DAT_40938af4);
  if (iVar1 == 0) {
    mali_sys_mutex_lock(DAT_40938af4);
    if (DAT_40938af0 != (int *)0x0) {
LAB_409319f0:
      mali_sys_mutex_unlock(DAT_40938af4);
      return DAT_40938af0;
    }
    DAT_40938af0 = (int *)mali_sys_calloc(1,0x4c);
    if (DAT_40938af0 != (int *)0x0) {
      FUN_409318f4();
      iVar1 = mali_sys_lock_create();
      DAT_40938af0[5] = iVar1;
      if (iVar1 != 0) {
        iVar1 = mali_sys_mutex_create();
        DAT_40938af0[6] = iVar1;
        if (iVar1 != 0) {
          iVar1 = __mali_named_list_allocate();
          *DAT_40938af0 = iVar1;
          if (iVar1 != 0) {
            iVar1 = __mali_named_list_allocate();
            DAT_40938af0[2] = iVar1;
            if (iVar1 != 0) {
              iVar1 = __mali_named_list_allocate();
              DAT_40938af0[0x12] = iVar1;
              if (iVar1 != 0) {
                puVar2 = (undefined4 *)mali_sys_malloc(0x110);
                DAT_40938af0[0xc] = (int)puVar2;
                if (((puVar2 != (undefined4 *)0x0) && (iVar1 = FUN_40927048(puVar2), iVar1 != 0)) &&
                   (iVar1 = FUN_40927cf8((int)DAT_40938af0), iVar1 == 0)) {
                  DAT_40938af0[0xb] = DAT_40938af0[0xb] | 0x20;
                  goto LAB_409319f0;
                }
              }
            }
          }
        }
      }
    }
    FUN_40931634();
    mali_sys_mutex_unlock(DAT_40938af4);
    mali_sys_mutex_destroy(DAT_40938af4);
    DAT_40938af4 = 0;
  }
  return (int *)0x0;
}



/* 40931b00 FUN_40931b00 */

/* Boundary evidence: original MIPS .pdata 40931b00..40931bb7. Semantic name remains unreviewed. */

undefined4 FUN_40931b00(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = FUN_409319b8();
  iVar2 = mali_base_context_create();
  piVar1[7] = iVar2;
  if ((iVar2 != 0) && (iVar2 = mali_mem_open(iVar2), iVar2 == 0)) {
    piVar1[0xb] = piVar1[0xb] | 1;
    iVar2 = mali_pp_open(piVar1[7]);
    if (iVar2 == 0) {
      piVar1[0xb] = piVar1[0xb] | 2;
      iVar2 = mali_gp_open(piVar1[7]);
      if (iVar2 == 0) {
        piVar1[0xb] = piVar1[0xb] | 4;
        iVar2 = FUN_40928f9c();
        if (iVar2 == 1) {
          piVar1[0xb] = piVar1[0xb] | 8;
          return 1;
        }
      }
    }
  }
  FUN_409317e0();
  return 0;
}



/* 40931bb8 FUN_40931bb8 */

/* Boundary evidence: original MIPS .pdata 40931bb8..40931be3. Semantic name remains unreviewed. */

void FUN_40931bb8(void)

{
  int *piVar1;
  
  piVar1 = FUN_409319b8();
  if (piVar1 != (int *)0x0) {
    mali_sys_lock_unlock(piVar1[5]);
  }
  return;
}



/* 40931be4 FUN_40931be4 */

/* Boundary evidence: original MIPS .pdata 40931be4..40931c0f. Semantic name remains unreviewed. */

void FUN_40931be4(void)

{
  int *piVar1;
  
  piVar1 = FUN_409319b8();
  if (piVar1 != (int *)0x0) {
    mali_sys_lock_lock(piVar1[5]);
  }
  return;
}



/* 40931c10 FUN_40931c10 */

/* Boundary evidence: original MIPS .pdata 40931c10..40931c6f. Semantic name remains unreviewed. */

void FUN_40931c10(int param_1)

{
  int *piVar1;
  
  if (param_1 == 0) {
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_lock(piVar1[5]);
    }
  }
  else if ((param_1 == 1) && (piVar1 = FUN_409319b8(), piVar1 != (int *)0x0)) {
    mali_sys_lock_unlock(piVar1[5]);
  }
  return;
}



/* 40931c70 FUN_40931c70 */

/* Boundary evidence: original MIPS .pdata 40931c70..40931d1b. Semantic name remains unreviewed. */

void FUN_40931c70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  
  if (((DAT_40938af0 != 0) && ((*(uint *)(DAT_40938af0 + 0x2c) & 0x20) != 0)) &&
     (piVar1 = FUN_409319b8(), piVar1 != (int *)0x0)) {
    piVar1 = FUN_409319b8();
    puVar3 = auStack_10;
    while (iVar2 = __mali_named_list_iterate_begin(*piVar1,puVar3), iVar2 != 0) {
      FUN_40934428(iVar2,1,param_3,param_4);
      piVar1 = FUN_409319b8();
      puVar3 = auStack_c;
    }
    FUN_40931634();
  }
  if (DAT_40938af4 != 0) {
    mali_sys_mutex_destroy(DAT_40938af4);
    DAT_40938af4 = 0;
  }
  return;
}



/* 40931d1c FUN_40931d1c */

/* Boundary evidence: original MIPS .pdata 40931d1c..40931d63. Semantic name remains unreviewed. */

undefined4 FUN_40931d1c(HMODULE param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_2 == 0) {
    FUN_40931c70(param_1,0,param_3,param_4);
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 40931ddc FUN_40931ddc */

undefined4 FUN_40931ddc(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *param_1;
  iVar3 = *(int *)(param_2 + 0xb8);
  if (iVar2 == iVar3) {
    return 1;
  }
  iVar4 = *(int *)(iVar3 + 0x24);
  if (*(int *)(iVar2 + 0x24) != iVar4) {
    return 0;
  }
  if (*(int *)(iVar2 + 0x14) != *(int *)(iVar3 + 0x14)) {
    return 0;
  }
  if (param_1[2] == 0x30a0) {
    if (*(int *)(iVar2 + 0x34) != *(int *)(iVar3 + 0x34)) {
      return 0;
    }
    if (*(int *)(iVar2 + 0x68) != *(int *)(iVar3 + 0x68)) {
      return 0;
    }
    if ((*(uint *)(iVar3 + 0x5c) & 1) != 0) goto LAB_40931e8c;
    uVar1 = *(uint *)(iVar3 + 0x5c) & 4;
  }
  else {
    if (param_1[2] != 0x30a1) goto LAB_40931e8c;
    uVar1 = *(uint *)(iVar3 + 0x5c) & 2;
  }
  if (uVar1 == 0) {
    return 0;
  }
LAB_40931e8c:
  if (iVar4 == 0x308e) {
    if (((*(int *)(iVar2 + 4) == *(int *)(iVar3 + 4)) &&
        (*(int *)(iVar2 + 8) == *(int *)(iVar3 + 8))) &&
       (*(int *)(iVar2 + 0xc) == *(int *)(iVar3 + 0xc))) {
      return 1;
    }
  }
  else if ((iVar4 != 0x308f) || (*(int *)(iVar2 + 0x10) == *(int *)(iVar3 + 0x10))) {
    return 1;
  }
  return 0;
}



/* 40931ef8 FUN_40931ef8 */

undefined4 FUN_40931ef8(int param_1,int *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  
  bVar1 = false;
  if (param_1 != 0) {
    piVar3 = (int *)(param_1 + 4);
    do {
      if (piVar3[-1] == 0x3038) {
        bVar1 = true;
      }
      else {
        if (piVar3[-1] != 0x3098) {
          if (param_3 == 0) {
            return 0;
          }
LAB_40931f80:
          *(undefined4 *)(param_3 + 0x10) = 0x3004;
          return 0;
        }
        if (*(int *)(param_3 + 0xc) != 0x30a0) {
          *(undefined4 *)(param_3 + 0x10) = 0x3004;
          return 0;
        }
        iVar2 = *piVar3;
        if ((iVar2 != 1) && (iVar2 != 2)) goto LAB_40931f80;
        *param_2 = iVar2;
      }
      prefetch(piVar3 + 3,0);
      piVar3 = piVar3 + 2;
    } while (!bVar1);
  }
  return 1;
}



/* 40931f94 FUN_40931f94 */

/* Boundary evidence: original MIPS .pdata 40931f94..40931ffb. Semantic name remains unreviewed. */

undefined4 * FUN_40931f94(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)mali_sys_malloc(0x2c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[5] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[6] = param_2;
    puVar1[7] = 0;
    *puVar1 = param_1;
    puVar1[9] = 1;
    puVar1[10] = 0;
  }
  return puVar1;
}



/* 40932004 FUN_40932004 */

/* Boundary evidence: original MIPS .pdata 40932004..409320e3. Semantic name remains unreviewed. */

void FUN_40932004(undefined4 *param_1,int *param_2,int *param_3)

{
  BOOL BVar1;
  int iVar2;
  
  FUN_40935b30();
  if (((param_1[0x28] == 1) &&
      ((iVar2 = *param_3, iVar2 == 0 ||
       ((param_1 != *(undefined4 **)(iVar2 + 8) && (param_1 != *(undefined4 **)(iVar2 + 4))))))) &&
     ((iVar2 = param_3[1], iVar2 == 0 ||
      ((param_1 != *(undefined4 **)(iVar2 + 8) && (param_1 != *(undefined4 **)(iVar2 + 4))))))) {
    param_3[4] = 0x3002;
  }
  else {
    if ((param_2 == (int *)0x0) || (iVar2 = FUN_40931ddc(param_2,(int)param_1), iVar2 != 0)) {
      if (((param_1[3] != 0) || (BVar1 = IsWindow((HWND)*param_1), BVar1 != 0)) ||
         (param_3 == (int *)0x0)) goto LAB_409320d8;
      iVar2 = 0x300b;
    }
    else {
      if (param_3 == (int *)0x0) goto LAB_409320d8;
      iVar2 = 0x3009;
    }
    param_3[4] = iVar2;
  }
LAB_409320d8:
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 409320e4 FUN_409320e4 */

/* Boundary evidence: original MIPS .pdata 409320e4..4093214f. Semantic name remains unreviewed. */

int FUN_409320e4(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 8) == 0x30a0) {
      FUN_4092836c(param_1);
    }
    else if (*(int *)(param_1 + 8) == 0x30a1) {
      FUN_409275d0(param_1);
    }
    mali_sys_free(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40932150 FUN_40932150 */

/* Boundary evidence: original MIPS .pdata 40932150..40932233. Semantic name remains unreviewed. */

undefined4 FUN_40932150(int param_1,int *param_2)

{
  int iVar1;
  
  if ((param_2[3] == 0x3038) || (param_1 != param_2[3])) {
    if (param_1 == 0x30a0) {
      param_2[3] = 0x30a0;
      FUN_40927558((int)param_2);
      iVar1 = param_2[1];
      if (iVar1 == 0) {
        return 1;
      }
      if (*(int *)(iVar1 + 0xc) == 0) {
        return 1;
      }
      iVar1 = FUN_409284f8(*(int *)(iVar1 + 0xc),*(int *)(iVar1 + 4),*(int *)(iVar1 + 8),
                           (int)param_2);
    }
    else {
      if (param_1 != 0x30a1) {
        iVar1 = 0x300c;
        goto LAB_40932214;
      }
      param_2[3] = 0x30a1;
      FUN_409282ec((int)param_2);
      iVar1 = *param_2;
      if (iVar1 == 0) {
        return 1;
      }
      if (*(int *)(iVar1 + 0xc) == 0) {
        return 1;
      }
      iVar1 = FUN_40927438(*(int *)(iVar1 + 0xc),*(int *)(iVar1 + 4),0,(int)param_2);
    }
    if (iVar1 == 0) {
      iVar1 = 0x3003;
LAB_40932214:
      param_2[4] = iVar1;
      return 0;
    }
  }
  return 1;
}



/* 40932234 FUN_40932234 */

/* Boundary evidence: original MIPS .pdata 40932234..409323db. Semantic name remains unreviewed. */

undefined4 FUN_40932234(uint param_1,uint param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_5 == 0) {
      return 0;
    }
    *(undefined4 *)(param_5 + 0x10) = 0x3008;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) == 0) {
LAB_409322ac:
    if (param_5 != 0) {
      *(undefined4 *)(param_5 + 0x10) = 0x3001;
    }
  }
  else {
    piVar2 = (int *)FUN_4092bc34(param_2,param_1,param_5);
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    if (param_4 == (int *)0x0) {
      if (param_5 == 0) {
        return 0;
      }
      uVar3 = 0x300c;
    }
    else {
      if ((*(uint *)(iVar1 + 0x20) & 2) != 0) goto LAB_409322ac;
      if (param_3 == 0x3028) {
        iVar1 = *(int *)(*piVar2 + 0x2c);
LAB_409323b4:
        *param_4 = iVar1;
        return 1;
      }
      if (param_3 == 0x3086) {
        if (piVar2[1] == 0) {
          iVar1 = 0x3038;
        }
        else {
          iVar1 = *(int *)(piVar2[1] + 0xc);
          if (iVar1 == 0) {
            iVar1 = 0x3084;
            goto LAB_409323b4;
          }
          if (iVar1 != 1) {
            if (iVar1 != 2) {
              return 0;
            }
            *param_4 = 0x3085;
            return 1;
          }
          iVar1 = 0x3084;
        }
LAB_4093234c:
        *param_4 = iVar1;
        return 1;
      }
      if (param_3 == 0x3097) {
        iVar1 = piVar2[2];
        goto LAB_409323b4;
      }
      if (param_3 == 0x3098) {
        iVar1 = piVar2[6];
        goto LAB_4093234c;
      }
      if (param_5 == 0) {
        return 0;
      }
      uVar3 = 0x3004;
    }
    *(undefined4 *)(param_5 + 0x10) = uVar3;
  }
  return 0;
}



/* 409323dc FUN_409323dc */

/* Boundary evidence: original MIPS .pdata 409323dc..40932483. Semantic name remains unreviewed. */

uint FUN_409323dc(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1[3] == 0x30a0) {
    if ((int *)param_1[1] == (int *)0x0) {
      return 0;
    }
    uVar1 = FUN_4092bfc8(*(int *)param_1[1],0,1);
    iVar2 = param_1[1];
  }
  else {
    if (param_1[3] != 0x30a1) {
      return 0;
    }
    if ((int *)*param_1 == (int *)0x0) {
      return 0;
    }
    uVar1 = FUN_4092bfc8(*(int *)*param_1,0,1);
    iVar2 = *param_1;
  }
  uVar1 = FUN_4092bfc8(*(int *)(iVar2 + 0xc),uVar1,3);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 | 0x40000000;
  }
  return uVar1;
}



/* 40932484 FUN_40932484 */

/* Boundary evidence: original MIPS .pdata 40932484..409325c7. Semantic name remains unreviewed. */

undefined4 FUN_40932484(int param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  uVar1 = FUN_4092bfc8(*param_3,0,1);
  if (param_1 == 0x3059) {
    piVar2 = (int *)param_2[1];
    if (param_3 == piVar2) {
      piVar2 = (int *)*param_2;
    }
    iVar3 = param_3[1];
    if (piVar2 == (int *)0x0) {
      uVar4 = 0;
    }
    else if ((iVar3 == piVar2[2]) || (uVar4 = 0, iVar3 == piVar2[1])) {
      uVar4 = 1;
    }
    *(undefined4 *)(iVar3 + 0xa0) = uVar4;
    iVar3 = FUN_4092d908(uVar1,(undefined4 *)param_3[1],0,param_2);
    if ((iVar3 == 1) && (param_3[1] == param_3[2])) {
      param_3[2] = 0;
    }
    param_3[1] = 0;
  }
  else if (param_1 == 0x305a) {
    piVar2 = (int *)param_2[1];
    if (param_3 == piVar2) {
      piVar2 = (int *)*param_2;
    }
    iVar3 = param_3[2];
    if (iVar3 != 0) {
      if ((piVar2 == (int *)0x0) || ((iVar3 != piVar2[2] && (iVar3 != piVar2[1])))) {
        uVar4 = 0;
      }
      *(undefined4 *)(iVar3 + 0xa0) = uVar4;
      FUN_4092d908(uVar1,(undefined4 *)param_3[2],0,param_2);
      param_3[2] = 0;
    }
  }
  return 1;
}



/* 409325c8 FUN_409325c8 */

/* Boundary evidence: original MIPS .pdata 409325c8..4093264b. Semantic name remains unreviewed. */

undefined4 FUN_409325c8(uint param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  
  if (param_3 == 1) {
    *(undefined4 *)(param_2 + 0x24) = 0;
  }
  iVar2 = *(int *)(param_2 + 0x14) + -1;
  *(int *)(param_2 + 0x14) = iVar2;
  if ((*(int *)(param_2 + 0x1c) == 1) && (iVar2 == 0)) {
    *(undefined4 *)(param_2 + 0x14) = 1;
  }
  iVar2 = FUN_409320e4(param_2);
  if (iVar2 == 0) {
    uVar1 = FUN_4092bd54(param_2,param_1,3,param_4,unaff_s1,unaff_s0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 4093264c FUN_4093264c */

/* Boundary evidence: original MIPS .pdata 4093264c..409326e3. Semantic name remains unreviewed. */

undefined4 FUN_4093264c(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0xc) == 0x30a0) {
    FUN_40928274(param_1);
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  if (*(int *)(param_1 + 0xc) == 0x30a1) {
    FUN_409273ac(param_1);
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  uVar1 = FUN_4092bfc8(*param_2,0,1);
  *(undefined4 *)(param_2[3] + 0x1c) = 0;
  *(undefined4 *)(param_2[3] + 4) = 0;
  FUN_409325c8(uVar1,param_2[3],0,param_4);
  param_2[3] = 0;
  return 1;
}



/* 409326e4 FUN_409326e4 */

/* Boundary evidence: original MIPS .pdata 409326e4..409327c3. Semantic name remains unreviewed. */

undefined4 FUN_409326e4(uint param_1,uint param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_3 != 0) {
    iVar1 = FUN_4092bb88(param_1);
    if (iVar1 == 0) {
      *(undefined4 *)(param_3 + 0x10) = 0x3008;
    }
    else {
      if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
        iVar2 = FUN_4092bc34(param_2,param_1,param_3);
        if (iVar2 == 0) {
          return 0;
        }
        if ((*(uint *)(iVar1 + 0x20) & 2) == 0) goto LAB_40932790;
      }
      *(undefined4 *)(param_3 + 0x10) = 0x3001;
    }
    return 0;
  }
  iVar2 = FUN_4092b978(param_2,param_1);
LAB_40932790:
  FUN_409325c8(param_1,iVar2,1,param_4);
  return 1;
}



/* 409327c4 FUN_409327c4 */

/* Boundary evidence: original MIPS .pdata 409327c4..409329a3. Semantic name remains unreviewed. */

void FUN_409327c4(uint param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int in_stack_00000048;
  
  FUN_40935a10();
  iVar6 = 0;
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (in_stack_00000048 != 0) {
      *(undefined4 *)(in_stack_00000048 + 0x10) = 0x3008;
    }
    goto LAB_4093299c;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) == 0) {
LAB_40932824:
    if (in_stack_00000048 == 0) goto LAB_4093299c;
    uVar5 = 0x3001;
  }
  else {
    iVar2 = FUN_4092bad8(param_2,param_1);
    if (iVar2 == 0) {
      if (in_stack_00000048 != 0) {
        *(undefined4 *)(in_stack_00000048 + 0x10) = 0x3005;
      }
      goto LAB_4093299c;
    }
    if ((*(uint *)(iVar1 + 0x20) & 2) != 0) goto LAB_40932824;
    if (param_3 == 0) {
LAB_409328c8:
      param_5 = 1;
      iVar1 = FUN_40931ef8(param_4,&param_5,in_stack_00000048);
      if (iVar1 == 1) {
        if (*(int *)(in_stack_00000048 + 0xc) == 0x30a0) {
          piVar3 = FUN_40928660(iVar2,iVar6,param_5,in_stack_00000048);
        }
        else {
          if (*(int *)(in_stack_00000048 + 0xc) != 0x30a1) {
            *(undefined4 *)(in_stack_00000048 + 0x10) = 0x3009;
            goto LAB_4093299c;
          }
          piVar3 = FUN_409276cc(iVar2,iVar6,param_5,in_stack_00000048);
        }
        if (piVar3 != (int *)0x0) {
          *piVar3 = iVar2;
          piVar3[1] = 0;
          piVar3[8] = 0;
          uVar4 = FUN_4092c4e8((int)piVar3,param_1,3);
          if ((uVar4 == 0) || ((uVar4 | 0x40000000) == 0)) {
            FUN_409320e4((int)piVar3);
            *(undefined4 *)(in_stack_00000048 + 0x10) = 0x3003;
          }
          else {
            piVar3[5] = 1;
          }
        }
      }
      goto LAB_4093299c;
    }
    iVar6 = FUN_4092b978(param_3,param_1);
    if (iVar6 == 0) {
      if (in_stack_00000048 != 0) {
        *(undefined4 *)(in_stack_00000048 + 0x10) = 0x3006;
      }
      goto LAB_4093299c;
    }
    if (*(int *)(in_stack_00000048 + 0xc) == *(int *)(iVar6 + 8)) goto LAB_409328c8;
    uVar5 = 0x3006;
  }
  *(undefined4 *)(in_stack_00000048 + 0x10) = uVar5;
LAB_4093299c:
                    /* WARNING: Subroutine does not return */
  FUN_40935a40(0x18);
}



/* 409329a4 FUN_409329a4 */

/* Boundary evidence: original MIPS .pdata 409329a4..40932fb3. Semantic name remains unreviewed. */

void FUN_409329a4(uint param_1,uint param_2,int *param_3,uint param_4,undefined4 param_5,int param_6
                 )

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int *in_stack_00000050;
  
  FUN_40935a70();
  param_6 = 0x3038;
  piVar7 = (int *)0x0;
  puVar8 = (undefined4 *)0x0;
  puVar9 = (undefined4 *)0x0;
  piVar6 = (int *)0x0;
  piVar4 = param_3;
  uVar5 = param_4;
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (in_stack_00000050 != (int *)0x0) {
      in_stack_00000050[4] = 0x3008;
    }
    goto LAB_40932ac8;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) == 0) {
    if (in_stack_00000050 != (int *)0x0) {
      in_stack_00000050[4] = 0x3001;
    }
    goto LAB_40932ac8;
  }
  if (((param_2 != 0) &&
      (piVar4 = in_stack_00000050,
      puVar8 = (undefined4 *)FUN_4092bc84(param_2,param_1,(int)in_stack_00000050),
      puVar8 == (undefined4 *)0x0)) ||
     ((param_3 != (int *)0x0 &&
      (piVar4 = in_stack_00000050,
      puVar9 = (undefined4 *)FUN_4092bc84((uint)param_3,param_1,(int)in_stack_00000050),
      puVar9 == (undefined4 *)0x0)))) goto LAB_40932ac8;
  if (param_4 == 0) {
    if ((puVar8 != (undefined4 *)0x0) || (puVar9 != (undefined4 *)0x0)) goto LAB_40932ab4;
LAB_40932ae4:
    if (((*(uint *)(iVar1 + 0x20) & 2) == 0) ||
       (((param_4 == 0 && (param_2 == 0)) && (param_3 == (int *)0x0)))) {
      if (piVar7 != (int *)0x0) {
        if (piVar7[2] == 0x30a0) {
          piVar6 = (int *)in_stack_00000050[1];
          iVar10 = 0x30a0;
LAB_40932b68:
          if (piVar7[8] != 1) goto LAB_40932b98;
          if (in_stack_00000050 == (int *)0x0) goto LAB_40932ac8;
          iVar1 = 0x300e;
        }
        else {
          if (piVar7[2] != 0x30a1) {
            iVar10 = 0x3038;
            goto LAB_40932b68;
          }
          piVar6 = (int *)*in_stack_00000050;
          iVar10 = 0x30a1;
          if (puVar8 == puVar9) goto LAB_40932b68;
          iVar1 = 0x3009;
        }
        in_stack_00000050[4] = iVar1;
        goto LAB_40932ac8;
      }
      piVar6 = (int *)FUN_4092c808(in_stack_00000050,&param_6);
      iVar10 = param_6;
LAB_40932b98:
      if (((piVar7 != (int *)0x0) && (piVar7[7] == 1)) &&
         ((piVar6 == (int *)0x0 || ((int *)piVar6[3] != piVar7)))) {
        if (in_stack_00000050 == (int *)0x0) goto LAB_40932ac8;
        iVar1 = 0x3002;
        goto LAB_40932ac0;
      }
      if (puVar9 == (undefined4 *)0x0) {
        iVar2 = 1;
      }
      else {
        piVar4 = in_stack_00000050;
        iVar2 = FUN_40932004(puVar9,piVar7,in_stack_00000050);
      }
      if (iVar2 != 1) goto LAB_40932ac8;
      if (puVar8 == (undefined4 *)0x0) {
        iVar2 = 1;
      }
      else {
        piVar4 = in_stack_00000050;
        iVar2 = FUN_40932004(puVar8,piVar7,in_stack_00000050);
      }
      if (iVar2 != 1) goto LAB_40932ac8;
      if (piVar6 != (int *)0x0) {
        if (((piVar7 == (int *)piVar6[3]) && (puVar8 == (undefined4 *)piVar6[1])) &&
           (puVar9 == (undefined4 *)piVar6[2])) goto LAB_40932ac8;
        if ((int *)piVar6[3] != (int *)0x0) {
          puVar3 = (undefined4 *)piVar6[1];
          if (((puVar8 != puVar3) && (puVar3[3] == 1)) && (puVar3[0x3f] == 0)) {
            piVar4 = piVar6;
            FUN_4093005c((int)puVar3,in_stack_00000050,(int)piVar6);
          }
          if ((((piVar7 != (int *)piVar6[3]) &&
               (iVar2 = FUN_4093264c((int)in_stack_00000050,piVar6,piVar4,uVar5), iVar2 != 1)) ||
              ((puVar8 != (undefined4 *)piVar6[1] &&
               (piVar4 = piVar6, iVar2 = FUN_40932484(0x3059,in_stack_00000050,piVar6), iVar2 != 1))
              )) || ((puVar9 != (undefined4 *)piVar6[2] &&
                     (piVar4 = piVar6, iVar2 = FUN_40932484(0x305a,in_stack_00000050,piVar6),
                     iVar2 != 1)))) goto LAB_40932ac8;
          if (((*(uint *)(iVar1 + 0x20) & 2) != 0) &&
             (((iVar2 = __mali_named_list_size(*(undefined4 *)(iVar1 + 0x2c)), iVar2 == 0 &&
               (iVar2 = __mali_named_list_size(*(undefined4 *)(iVar1 + 0x28)), iVar2 == 0)) &&
              (iVar2 = __mali_named_list_size(*(undefined4 *)(in_stack_00000050[2] + 0x48)),
              iVar2 == 0)))) {
            FUN_40934428(iVar1,0,piVar4,uVar5);
          }
        }
      }
      if ((puVar8 == (undefined4 *)0x0) || (piVar7 == (int *)0x0)) goto LAB_40932ac8;
      if (piVar6 != (int *)0x0) {
LAB_40932d90:
        if (iVar10 == 0x30a0) {
          in_stack_00000050[1] = (int)piVar6;
        }
        else if (iVar10 == 0x30a1) {
          *in_stack_00000050 = (int)piVar6;
        }
        if (piVar7[2] == 0x30a0) {
          in_stack_00000050[7] = piVar7[3];
          piVar4 = in_stack_00000050;
          iVar10 = FUN_409284f8((int)piVar7,(int)puVar8,(int)puVar9,(int)in_stack_00000050);
          if (iVar10 == 0) {
            if (piVar7 == (int *)piVar6[3]) {
              FUN_40928274((int)in_stack_00000050);
              *(undefined4 *)(piVar6[3] + 0x1c) = 0;
              FUN_409325c8(param_1,(int)piVar7,0,piVar4);
              *(undefined4 *)(piVar6[3] + 4) = 0;
              piVar6[3] = 0;
            }
            if (puVar8 == (undefined4 *)piVar6[1]) {
              FUN_40932484(0x3059,in_stack_00000050,piVar6);
            }
            if (puVar9 == (undefined4 *)piVar6[2]) {
              FUN_40932484(0x305a,in_stack_00000050,piVar6);
            }
            mali_sys_free(in_stack_00000050[1]);
            in_stack_00000050[7] = 0;
            in_stack_00000050[1] = 0;
            goto LAB_40932d78;
          }
        }
        else if (piVar7[2] == 0x30a1) {
          in_stack_00000050[6] = piVar7[3];
          piVar4 = in_stack_00000050;
          iVar10 = FUN_40927438((int)piVar7,(int)puVar8,1,(int)in_stack_00000050);
          if (iVar10 == 0) {
            if (piVar7 == (int *)piVar6[3]) {
              FUN_409273ac((int)in_stack_00000050);
              *(undefined4 *)(piVar6[3] + 0x1c) = 0;
              FUN_409325c8(param_1,(int)piVar7,0,piVar4);
              *(undefined4 *)(piVar6[3] + 4) = 0;
              piVar6[3] = 0;
            }
            if (puVar8 == (undefined4 *)piVar6[1]) {
              FUN_40932484(0x3059,in_stack_00000050,piVar6);
            }
            if (puVar9 == (undefined4 *)piVar6[2]) {
              FUN_40932484(0x305a,in_stack_00000050,piVar6);
            }
            mali_sys_free(*in_stack_00000050);
            in_stack_00000050[6] = 0;
            *in_stack_00000050 = 0;
            goto LAB_40932d78;
          }
        }
        *piVar6 = iVar1;
        if (piVar7 != (int *)piVar6[3]) {
          piVar7[5] = piVar7[5] + 1;
        }
        piVar6[3] = (int)piVar7;
        piVar7[7] = 1;
        piVar7[1] = (int)puVar8;
        if (puVar8 != (undefined4 *)piVar6[1]) {
          puVar8[0x27] = puVar8[0x27] + 1;
        }
        piVar6[1] = (int)puVar8;
        puVar8[0x28] = 1;
        if (puVar9 != (undefined4 *)piVar6[2]) {
          puVar9[0x27] = puVar9[0x27] + 1;
        }
        piVar6[2] = (int)puVar9;
        puVar9[0x28] = 1;
        puVar8[0x2b] = 0;
        iVar1 = *(int *)(*(int *)(piVar6[1] + 0xb8) + 0x4c);
        if (iVar1 < 1) {
          iVar1 = *(int *)(*(int *)(piVar6[1] + 0xb8) + 0x48);
          if (iVar1 < 0) {
            puVar8[0x2b] = iVar1;
          }
        }
        else {
          puVar8[0x2b] = iVar1;
        }
        goto LAB_40932ac8;
      }
      piVar6 = (int *)mali_sys_malloc(0x10);
      if (piVar6 != (int *)0x0) {
        *piVar6 = 0;
        piVar6[1] = 0;
        piVar6[2] = 0;
        piVar6[3] = 0;
        goto LAB_40932d90;
      }
      if (in_stack_00000050 == (int *)0x0) goto LAB_40932ac8;
LAB_40932d78:
      iVar1 = 0x3003;
    }
    else {
      if (in_stack_00000050 == (int *)0x0) goto LAB_40932ac8;
      iVar1 = 0x3001;
    }
  }
  else {
    piVar4 = in_stack_00000050;
    piVar7 = (int *)FUN_4092bc34(param_4,param_1,(int)in_stack_00000050);
    if (piVar7 == (int *)0x0) goto LAB_40932ac8;
    if ((puVar8 != (undefined4 *)0x0) && (puVar9 != (undefined4 *)0x0)) goto LAB_40932ae4;
LAB_40932ab4:
    if (in_stack_00000050 == (int *)0x0) goto LAB_40932ac8;
    iVar1 = 0x3009;
  }
LAB_40932ac0:
  in_stack_00000050[4] = iVar1;
LAB_40932ac8:
                    /* WARNING: Subroutine does not return */
  FUN_40935aa8(0x18);
}



/* 40932fb4 FUN_40932fb4 */

/* Boundary evidence: original MIPS .pdata 40932fb4..4093345b. Semantic name remains unreviewed. */

undefined4
FUN_40932fb4(int param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  
  bVar4 = false;
  if (param_2 != (undefined4 *)0x0) {
    do {
      switch(*param_2) {
      case 0x3020:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        *param_3 = iVar2;
        break;
      case 0x3021:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        param_3[5] = iVar2;
        break;
      case 0x3022:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        param_3[3] = iVar2;
        break;
      case 0x3023:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        param_3[2] = iVar2;
        break;
      case 0x3024:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        param_3[1] = iVar2;
        break;
      case 0x3025:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        param_3[0xd] = iVar2;
        break;
      case 0x3026:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        param_3[0x1a] = iVar2;
        break;
      case 0x3027:
        iVar2 = 0;
        piVar3 = &DAT_40924524;
        do {
          if (param_2[1] == *piVar3) {
            param_3[10] = param_2[1];
            break;
          }
          iVar2 = iVar2 + 1;
          piVar3 = piVar3 + 1;
        } while (iVar2 < 4);
        if (iVar2 == 4) goto switchD_40933010_caseD_3030;
        break;
      case 0x3028:
        param_3[0xb] = param_2[1];
        break;
      case 0x3029:
        iVar2 = param_2[1];
        param_3[0xe] = iVar2;
        if (iVar2 == -1) goto switchD_40933010_caseD_3030;
        break;
      case 0x302a:
      case 0x302b:
      case 0x302c:
      case 0x302e:
        break;
      case 0x302d:
        iVar2 = param_2[1];
        if (((iVar2 != -1) && (iVar2 != 1)) && (iVar2 != 0)) goto switchD_40933010_caseD_3030;
        param_3[0x14] = iVar2;
        break;
      case 0x302f:
        param_3[0x16] = param_2[1];
        break;
      default:
        goto switchD_40933010_caseD_3030;
      case 0x3031:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        param_3[0x19] = iVar2;
        break;
      case 0x3032:
        iVar2 = 0;
        piVar3 = &DAT_40924540;
        do {
          if (param_2[1] == *piVar3) {
            param_3[0x18] = param_2[1];
            break;
          }
          iVar2 = iVar2 + 1;
          piVar3 = piVar3 + 1;
        } while (iVar2 < 2);
        if (iVar2 == 2) goto switchD_40933010_caseD_3030;
        break;
      case 0x3033:
        uVar1 = param_2[1];
        if ((uVar1 != 0xffffffff) && ((uVar1 & 0xfffff998) != 0)) goto switchD_40933010_caseD_3030;
        param_3[0x1b] = uVar1;
        break;
      case 0x3034:
        iVar2 = 0;
        piVar3 = &DAT_40924534;
        do {
          if (param_2[1] == *piVar3) {
            param_3[0x1c] = param_2[1];
            break;
          }
          iVar2 = iVar2 + 1;
          piVar3 = piVar3 + 1;
        } while (iVar2 < 3);
        goto joined_r0x409331a4;
      case 0x3035:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        param_3[0x1f] = iVar2;
        break;
      case 0x3036:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        param_3[0x1e] = iVar2;
        break;
      case 0x3037:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        param_3[0x1d] = iVar2;
        break;
      case 0x3038:
        bVar4 = true;
        break;
      case 0x3039:
        iVar2 = param_2[1];
        if (((iVar2 != -1) && (iVar2 != 1)) && (iVar2 != 0)) goto switchD_40933010_caseD_3030;
        param_3[7] = iVar2;
        break;
      case 0x303a:
        iVar2 = param_2[1];
        if (((iVar2 != -1) && (iVar2 != 1)) && (iVar2 != 0)) goto switchD_40933010_caseD_3030;
        param_3[8] = iVar2;
        break;
      case 0x303b:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        param_3[0x13] = iVar2;
        break;
      case 0x303c:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        param_3[0x12] = iVar2;
        break;
      case 0x303d:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        param_3[4] = iVar2;
        break;
      case 0x303e:
        iVar2 = param_2[1];
        if ((iVar2 != -1) && (iVar2 < 0)) goto switchD_40933010_caseD_3030;
        param_3[6] = iVar2;
        break;
      case 0x303f:
        iVar2 = 0;
        piVar3 = &DAT_40924518;
        do {
          if (param_2[1] == *piVar3) {
            param_3[9] = param_2[1];
            break;
          }
          iVar2 = iVar2 + 1;
          prefetch(piVar3 + 2,0);
          piVar3 = piVar3 + 1;
        } while (iVar2 < 3);
joined_r0x409331a4:
        if (iVar2 == 3) {
switchD_40933010_caseD_3030:
          if (param_1 != 0) {
            *(undefined4 *)(param_1 + 0x10) = 0x3004;
          }
          return 0;
        }
        break;
      case 0x3040:
        uVar1 = param_2[1];
        if ((uVar1 != 0xffffffff) && ((uVar1 & 0xfffffff0) != 0)) goto switchD_40933010_caseD_3030;
        param_3[0x17] = uVar1;
        break;
      case 0x3041:
        *param_4 = param_2[1];
        *param_5 = 1;
        break;
      case 0x3042:
        uVar1 = param_2[1];
        if ((uVar1 != 0xffffffff) && ((uVar1 & 0xfffffff0) != 0)) goto switchD_40933010_caseD_3030;
        param_3[0xc] = uVar1;
      }
      param_2 = param_2 + 2;
    } while (!bVar4);
  }
  return 1;
}



/* 4093345c FUN_4093345c */

void FUN_4093345c(undefined4 *param_1)

{
  param_1[9] = 0x308e;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0xffffffff;
  param_1[8] = 0xffffffff;
  param_1[10] = 0xffffffff;
  param_1[0xb] = 0xffffffff;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x12] = 0xffffffff;
  param_1[0x13] = 0xffffffff;
  param_1[0x14] = 0xffffffff;
  param_1[0x16] = 0xffffffff;
  param_1[0x17] = 1;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 4;
  param_1[0x1c] = 0x3038;
  param_1[0x1d] = 0xffffffff;
  param_1[0x1e] = 0xffffffff;
  param_1[0x1f] = 0xffffffff;
  return;
}



/* 409334e4 FUN_409334e4 */

/* Boundary evidence: original MIPS .pdata 409334e4..40933717. Semantic name remains unreviewed. */

void FUN_409334e4(uint *param_1,uint *param_2)

{
  uint uVar1;
  
  FUN_40935b30();
  uVar1 = *param_2;
  FUN_4092bad8(*param_1,DAT_40938ae8);
  FUN_4092bad8(uVar1,DAT_40938ae8);
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 40933718 FUN_40933718 */

/* Boundary evidence: original MIPS .pdata 40933718..409339b3. Semantic name remains unreviewed. */

undefined4
FUN_40933718(uint param_1,uint param_2,undefined4 param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_5 == 0) {
      return 0;
    }
    *(undefined4 *)(param_5 + 0x10) = 0x3008;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 1) == 0) {
LAB_40933788:
    if (param_5 == 0) {
      return 0;
    }
    *(undefined4 *)(param_5 + 0x10) = 0x3001;
    return 0;
  }
  puVar2 = (undefined4 *)FUN_4092bad8(param_2,param_1);
  if (puVar2 == (undefined4 *)0x0) {
    if (param_5 == 0) {
      return 0;
    }
    *(undefined4 *)(param_5 + 0x10) = 0x3005;
    return 0;
  }
  if (param_4 == (undefined4 *)0x0) {
    if (param_5 == 0) {
      return 0;
    }
    uVar3 = 0x300c;
LAB_40933988:
    *(undefined4 *)(param_5 + 0x10) = uVar3;
    return 0;
  }
  if ((*(uint *)(iVar1 + 0x20) & 2) != 0) goto LAB_40933788;
  switch(param_3) {
  case 0x3020:
    *param_4 = *puVar2;
    return 1;
  case 0x3021:
    uVar3 = puVar2[5];
    goto LAB_40933884;
  case 0x3022:
    uVar3 = puVar2[3];
    break;
  case 0x3023:
    uVar3 = puVar2[2];
    goto LAB_40933884;
  case 0x3024:
    uVar3 = puVar2[1];
    break;
  case 0x3025:
    uVar3 = puVar2[0xd];
    break;
  case 0x3026:
    uVar3 = puVar2[0x1a];
    goto LAB_40933884;
  case 0x3027:
    uVar3 = puVar2[10];
    goto LAB_40933884;
  case 0x3028:
    uVar3 = puVar2[0xb];
    break;
  case 0x3029:
    uVar3 = puVar2[0xe];
    goto LAB_40933884;
  case 0x302a:
    uVar3 = puVar2[0x10];
    goto LAB_40933884;
  case 0x302b:
    uVar3 = puVar2[0x11];
    break;
  case 0x302c:
    uVar3 = puVar2[0xf];
    break;
  case 0x302d:
    uVar3 = puVar2[0x14];
    goto LAB_40933884;
  case 0x302e:
    uVar3 = puVar2[0x15];
    break;
  case 0x302f:
    uVar3 = puVar2[0x16];
    goto LAB_40933884;
  default:
    if (param_5 == 0) {
      return 0;
    }
    uVar3 = 0x3004;
    goto LAB_40933988;
  case 0x3031:
    uVar3 = puVar2[0x19];
    break;
  case 0x3032:
    uVar3 = puVar2[0x18];
    goto LAB_40933884;
  case 0x3033:
    uVar3 = puVar2[0x1b];
    break;
  case 0x3034:
    uVar3 = puVar2[0x1c];
    goto LAB_40933884;
  case 0x3035:
    uVar3 = puVar2[0x1f];
    break;
  case 0x3036:
    uVar3 = puVar2[0x1e];
    goto LAB_40933884;
  case 0x3037:
    uVar3 = puVar2[0x1d];
    break;
  case 0x3039:
    uVar3 = puVar2[7];
    break;
  case 0x303a:
    uVar3 = puVar2[8];
    goto LAB_40933884;
  case 0x303b:
    uVar3 = puVar2[0x13];
    break;
  case 0x303c:
    uVar3 = puVar2[0x12];
    goto LAB_40933884;
  case 0x303d:
    uVar3 = puVar2[4];
    break;
  case 0x303e:
    uVar3 = puVar2[6];
    goto LAB_40933884;
  case 0x303f:
    uVar3 = puVar2[9];
    break;
  case 0x3040:
    uVar3 = puVar2[0x17];
    break;
  case 0x3042:
    uVar3 = puVar2[0xc];
LAB_40933884:
    *param_4 = uVar3;
    return 1;
  }
  *param_4 = uVar3;
  return 1;
}



/* 409339b4 FUN_409339b4 */

/* Boundary evidence: original MIPS .pdata 409339b4..40933aaf. Semantic name remains unreviewed. */

undefined4 FUN_409339b4(uint param_1,uint *param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 == 0) {
    if (param_5 != 0) {
      *(undefined4 *)(param_5 + 0x10) = 0x3008;
    }
  }
  else {
    if ((*(uint *)(iVar1 + 0x20) & 1) != 0) {
      if (param_4 == (int *)0x0) {
        if (param_5 == 0) {
          return 0;
        }
        *(undefined4 *)(param_5 + 0x10) = 0x300c;
        return 0;
      }
      if ((*(uint *)(iVar1 + 0x20) & 2) == 0) {
        iVar1 = __mali_named_list_size(*(undefined4 *)(iVar1 + 0x24));
        if (param_2 != (uint *)0x0) {
          if (iVar1 < param_3) {
            param_3 = iVar1;
          }
          iVar1 = FUN_4092bf18(param_2,param_1,param_3);
        }
        *param_4 = iVar1;
        return 1;
      }
    }
    if (param_5 != 0) {
      *(undefined4 *)(param_5 + 0x10) = 0x3001;
    }
  }
  return 0;
}



/* 40933ab0 FUN_40933ab0 */

/* Boundary evidence: original MIPS .pdata 40933ab0..40933b27. Semantic name remains unreviewed. */

void FUN_40933ab0(int param_1,HANDLE param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  
  FUN_40935b30();
  param_5 = 0;
  piVar1 = (int *)__mali_named_list_iterate_begin(*(undefined4 *)(param_1 + 0x24),&param_5);
  while ((piVar1 != (int *)0x0 &&
         (((piVar1[0x1b] & 2U) == 0 || (iVar2 = FUN_40929fc4(param_2,piVar1), iVar2 != 1))))) {
    piVar1 = (int *)__mali_named_list_iterate_next(*(undefined4 *)(param_1 + 0x24),&param_5);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x18);
}



/* 40933b28 FUN_40933b28 */

/* Boundary evidence: original MIPS .pdata 40933b28..40934153. Semantic name remains unreviewed. */

void FUN_40933b28(uint param_1,undefined4 *param_2,uint *param_3,uint param_4,undefined4 param_5,
                 undefined4 param_6,int param_7,HANDLE param_8,uint *param_9,undefined4 param_10,
                 int param_11,int param_12,int param_13,int param_14,uint param_15,uint *param_16,
                 int param_17,int param_18,int param_19,int param_20,int param_21,int param_22,
                 int param_23,int param_24,int param_25,int param_26,int param_27,int param_28,
                 uint param_29,int param_30,int param_31)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  int in_stack_00000088;
  int in_stack_0000008c;
  int in_stack_00000090;
  int in_stack_00000098;
  uint in_stack_0000009c;
  int in_stack_000000a0;
  int in_stack_000000a4;
  int in_stack_000000a8;
  uint in_stack_000000ac;
  int in_stack_000000b0;
  int in_stack_000000b4;
  int in_stack_000000b8;
  int in_stack_000000bc;
  uint *in_stack_00000198;
  int in_stack_0000019c;
  
  FUN_40935a70();
  param_7 = 0;
  uVar8 = 0;
  param_8 = (HANDLE)0x0;
  param_15 = param_4;
  param_16 = param_3;
  iVar2 = FUN_4092bb88(param_1);
  puVar9 = in_stack_00000198;
  if (iVar2 == 0) {
    if (in_stack_0000019c != 0) {
      *(undefined4 *)(in_stack_0000019c + 0x10) = 0x3008;
    }
    goto LAB_40934148;
  }
  if ((*(uint *)(iVar2 + 0x20) & 1) != 0) {
    if (in_stack_00000198 == (uint *)0x0) {
      if (in_stack_0000019c == 0) goto LAB_40934148;
      uVar7 = 0x300c;
LAB_40933bcc:
      *(undefined4 *)(in_stack_0000019c + 0x10) = uVar7;
      goto LAB_40934148;
    }
    if ((*(uint *)(iVar2 + 0x20) & 2) == 0) {
      FUN_4093345c(&param_17);
      iVar3 = FUN_40932fb4(in_stack_0000019c,param_2,&param_17,&param_8,&param_7);
      if (iVar3 != 1) goto LAB_40934148;
      *puVar9 = 0;
      if (param_28 != -1) {
        if (((0 < (int)param_4) && (uVar8 = FUN_4092be94(param_28,param_1), uVar8 != 0)) &&
           (*puVar9 = 1, param_3 != (uint *)0x0)) {
          *param_3 = uVar8;
        }
        goto LAB_40934148;
      }
      if ((in_stack_000000ac & 4) == 0) {
        param_12 = -1;
      }
      else {
        param_12 = in_stack_00000098;
      }
      if (in_stack_000000b0 == 0x3038) {
        param_14 = -1;
        param_13 = -1;
        param_11 = -1;
      }
      else {
        param_11 = in_stack_000000bc;
        param_13 = in_stack_000000b8;
        param_14 = in_stack_000000b4;
      }
      uVar10 = in_stack_000000ac;
      if (param_7 == 1) {
        iVar3 = GetObjectW(param_8,0x54,&stack0x00000108);
        if (iVar3 == 0) {
          if (in_stack_0000019c == 0) goto LAB_40934148;
          uVar7 = 0x300a;
          goto LAB_40933bcc;
        }
        uVar10 = 2;
      }
      piVar4 = (int *)__mali_named_list_iterate_begin(*(undefined4 *)(iVar2 + 0x24),&param_10);
      iVar1 = param_14;
      iVar3 = param_12;
      if (piVar4 != (int *)0x0) {
        param_9 = (uint *)&stack0x000000c8;
        do {
          if ((((((((((param_17 == -1) || (param_17 <= *piVar4)) &&
                    ((param_18 == -1 || (param_18 <= piVar4[1])))) &&
                   ((param_19 == -1 || (param_19 <= piVar4[2])))) &&
                  ((param_20 == -1 || (param_20 <= piVar4[3])))) &&
                 (((((param_21 == -1 || (param_21 <= piVar4[4])) &&
                    ((param_22 == -1 || (param_22 <= piVar4[5])))) &&
                   ((param_23 == -1 || (param_23 <= piVar4[6])))) &&
                  ((param_24 == -1 || (piVar4[7] == param_24)))))) &&
                ((((param_25 == -1 || (piVar4[8] == param_25)) &&
                  ((param_26 == -1 || (piVar4[9] == param_26)))) &&
                 (((param_27 == -1 || (piVar4[10] == param_27)) &&
                  ((param_29 == 0 || ((piVar4[0xc] & param_29) != 0)))))))) &&
               ((((param_30 == -1 || (param_30 <= piVar4[0xd])) &&
                 ((param_31 == -1 || (piVar4[0xe] == param_31)))) &&
                ((in_stack_00000088 == -1 || (piVar4[0x12] == in_stack_00000088)))))) &&
              ((in_stack_0000008c == -1 || (piVar4[0x13] == in_stack_0000008c)))) &&
             (((((in_stack_00000090 == -1 || (piVar4[0x14] == in_stack_00000090)) &&
                ((iVar3 == -1 || (piVar4[0x16] == iVar3)))) &&
               (((in_stack_0000009c == 0xffffffff ||
                 ((piVar4[0x17] & in_stack_0000009c) == in_stack_0000009c)) &&
                (((in_stack_000000a0 == -1 || (in_stack_000000a0 <= piVar4[0x18])) &&
                 ((((in_stack_000000a4 == -1 || (in_stack_000000a4 <= piVar4[0x19])) &&
                   ((in_stack_000000a8 == -1 || (in_stack_000000a8 <= piVar4[0x1a])))) &&
                  ((uVar10 == 0xffffffff || ((piVar4[0x1b] & uVar10) == uVar10)))))))))) &&
              (((in_stack_000000b0 == -1 || (piVar4[0x1c] == in_stack_000000b0)) &&
               ((((((iVar1 == -1 || (piVar4[0x1d] == iVar1)) &&
                   ((param_13 == -1 || (piVar4[0x1e] == param_13)))) &&
                  ((param_11 == -1 || (piVar4[0x1f] == param_11)))) &&
                 ((param_7 != 1 || (iVar5 = FUN_40929fc4(param_8,piVar4), iVar5 != 0)))) &&
                (uVar8 < 0xf)))))))) {
            uVar6 = FUN_4092bfc8((int)piVar4,param_1,4);
            if (uVar6 == 0) {
              uVar6 = 0;
            }
            else {
              uVar6 = uVar6 | 0x60000000;
            }
            uVar8 = uVar8 + 1;
            *param_9 = uVar6;
            param_9 = param_9 + 1;
          }
          piVar4 = (int *)__mali_named_list_iterate_next(*(undefined4 *)(iVar2 + 0x24),&param_10);
          puVar9 = in_stack_00000198;
          param_4 = param_15;
          param_3 = param_16;
        } while (piVar4 != (int *)0x0);
      }
      if (param_3 == (uint *)0x0) {
        *puVar9 = uVar8;
      }
      else if (uVar8 != 0) {
        DAT_40938aec = (uint)(0 < param_18);
        if (0 < param_19) {
          DAT_40938aec = 0 < param_18 | 2;
        }
        if (0 < param_20) {
          DAT_40938aec = DAT_40938aec | 4;
        }
        if (0 < param_22) {
          DAT_40938aec = DAT_40938aec | 8;
        }
        if (0 < param_21) {
          DAT_40938aec = DAT_40938aec | 0x10;
        }
        DAT_40938ae8 = param_1;
        mali_sys_qsort(&stack0x000000c8,uVar8,4,FUN_409334e4);
        uVar10 = param_4;
        if ((int)uVar8 <= (int)param_4) {
          uVar10 = uVar8;
        }
        mali_sys_memcpy(param_3,&stack0x000000c8,uVar10 << 2);
        if ((int)uVar8 <= (int)param_4) {
          param_4 = uVar8;
        }
        *puVar9 = param_4;
      }
      goto LAB_40934148;
    }
  }
  if (in_stack_0000019c != 0) {
    *(undefined4 *)(in_stack_0000019c + 0x10) = 0x3001;
  }
LAB_40934148:
                    /* WARNING: Subroutine does not return */
  FUN_40935aa8(0x160);
}



/* 40934154 FUN_40934154 */

/* Boundary evidence: original MIPS .pdata 40934154..409341a3. Semantic name remains unreviewed. */

void FUN_40934154(uint param_1)

{
  int iVar1;
  undefined *puVar2;
  
  FUN_40935b30();
  iVar1 = FUN_4092bb88(param_1);
  if (iVar1 != 0) {
    puVar2 = &DAT_409382cc;
    iVar1 = 0xf;
    do {
      FUN_4092c4e8((int)puVar2,param_1,4);
      iVar1 = iVar1 + -1;
      puVar2 = puVar2 + 0x88;
    } while (iVar1 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 409341a4 FUN_409341a4 */

/* Boundary evidence: original MIPS .pdata 409341a4..409341d7. Semantic name remains unreviewed. */

void FUN_409341a4(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = FUN_409319b8();
  iVar2 = piVar1[1];
  piVar1[1] = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    FUN_409317e0();
  }
  return;
}



/* 409341d8 FUN_409341d8 */

/* Boundary evidence: original MIPS .pdata 409341d8..40934233. Semantic name remains unreviewed. */

undefined4 FUN_409341d8(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = FUN_409319b8();
  if ((piVar1[1] == 0) && (iVar2 = FUN_40931b00(), iVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
    piVar1[1] = piVar1[1] + 1;
  }
  return uVar3;
}



/* 40934234 FUN_40934234 */

/* Boundary evidence: original MIPS .pdata 40934234..4093429b. Semantic name remains unreviewed. */

undefined4 FUN_40934234(undefined4 *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_1[3] == 0x30a0) {
    piVar2 = (int *)param_1[1];
  }
  else {
    if (param_1[3] != 0x30a1) {
      return 0;
    }
    piVar2 = (int *)*param_1;
  }
  if ((piVar2 != (int *)0x0) && (piVar2[3] != 0)) {
    uVar1 = FUN_4092bfc8(*piVar2,0,1);
    return uVar1;
  }
  return 0;
}



/* 4093429c FUN_4093429c */

/* Boundary evidence: original MIPS .pdata 4093429c..40934427. Semantic name remains unreviewed. */

void FUN_4093429c(uint param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  FUN_40935a10();
  puVar1 = (undefined4 *)FUN_4092bb88(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    if (param_4 != 0) {
      *(undefined4 *)(param_4 + 0x10) = 0x3008;
    }
    goto LAB_40934420;
  }
  if (((puVar1[8] & 1) == 0) && (iVar2 = FUN_409341d8(), iVar2 == 0)) {
    if (param_4 == 0) goto LAB_40934420;
  }
  else {
    iVar2 = FUN_40928f20((HDC)*puVar1);
    if (iVar2 == 0) {
      if ((puVar1[8] & 1) == 0) {
        piVar3 = FUN_409319b8();
        iVar2 = piVar3[1];
        piVar3[1] = iVar2 + -1;
        if (iVar2 + -1 == 0) {
          FUN_409317e0();
        }
      }
      if (param_4 != 0) {
        *(undefined4 *)(param_4 + 0x10) = 0x3008;
      }
      goto LAB_40934420;
    }
    if ((puVar1[8] & 1) != 0) {
LAB_409343f0:
      puVar1[8] = puVar1[8] & 0xfffffffd | 1;
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = 1;
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = 4;
      }
      goto LAB_40934420;
    }
    FUN_409319b8();
    iVar2 = FUN_40929c30();
    if (iVar2 != 0) {
      iVar2 = FUN_4092b3cc((int)puVar1);
      if (iVar2 != 0) {
        FUN_40929494(*puVar1,puVar1 + 1);
        FUN_40934154(param_1);
        goto LAB_409343f0;
      }
      FUN_409296a4();
    }
    piVar3 = FUN_409319b8();
    iVar2 = piVar3[1];
    piVar3[1] = iVar2 + -1;
    if (iVar2 + -1 == 0) {
      FUN_409317e0();
    }
  }
  *(undefined4 *)(param_4 + 0x10) = 0x3003;
LAB_40934420:
                    /* WARNING: Subroutine does not return */
  FUN_40935a40(0x10);
}



/* 40934428 FUN_40934428 */

/* Boundary evidence: original MIPS .pdata 40934428..409344ef. Semantic name remains unreviewed. */

void FUN_40934428(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = FUN_409319b8();
  iVar2 = FUN_4092bfc8(param_1,0,1);
  iVar3 = param_2;
  FUN_4092c754(piVar1[0x12],iVar2,param_2,param_4);
  FUN_409296a4();
  FUN_4092c128(param_1,param_2,iVar3,param_4);
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  if (param_2 == 1) {
    mali_sys_free(param_1);
  }
  else {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffc;
    piVar1 = FUN_409319b8();
    iVar3 = piVar1[1];
    piVar1[1] = iVar3 + -1;
    if (iVar3 + -1 == 0) {
      FUN_409317e0();
    }
  }
  return;
}



/* 409344f0 FUN_409344f0 */

/* Boundary evidence: original MIPS .pdata 409344f0..40934607. Semantic name remains unreviewed. */

undefined4 FUN_409344f0(uint param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint unaff_s4;
  uint unaff_s5;
  
  uVar7 = 1;
  bVar1 = true;
  iVar2 = FUN_4092bb88(param_1);
  if (iVar2 == 0) {
    if (param_2 != (int *)0x0) {
      param_2[4] = 0x3008;
    }
    uVar7 = 0;
  }
  else {
    uVar6 = *(uint *)(iVar2 + 0x20);
    if (((uVar6 & 1) != 0) && ((uVar6 & 2) == 0)) {
      *(uint *)(iVar2 + 0x20) = uVar6 | 2;
      iVar3 = FUN_4092c3c4(param_1,param_2);
      iVar4 = FUN_4092c2c8(param_1,param_2,param_3,param_4,unaff_s5,unaff_s4);
      if (*(int *)(param_2[2] + 0x48) != 0) {
        iVar5 = __mali_named_list_size();
        bVar1 = false;
        if (iVar5 == 0) {
          bVar1 = true;
        }
      }
      if (((iVar3 == 1) && (iVar4 == 1)) && (bVar1)) {
        FUN_40934428(iVar2,0,param_3,param_4);
      }
    }
  }
  return uVar7;
}



/* 40934608 FUN_40934608 */

/* Boundary evidence: original MIPS .pdata 40934608..409346c3. Semantic name remains unreviewed. */

void FUN_40934608(HDC param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  FUN_40935b30();
  if (param_1 == (HDC)0x0) {
    param_1 = (HDC)0x0;
  }
  iVar1 = FUN_40928f20(param_1);
  if ((iVar1 != 0) && (iVar1 = FUN_4092b75c((int)param_1), iVar1 == 0)) {
    puVar2 = (undefined4 *)mali_sys_malloc(0x30);
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = 1;
      *puVar2 = param_1;
      puVar2[8] = 0;
      puVar2[9] = 0;
      puVar2[10] = 0;
      puVar2[0xb] = 0;
      puVar2[3] = 0;
      puVar2[2] = 0;
      puVar2[1] = 0;
      puVar2[6] = 0;
      puVar2[5] = 0;
      puVar2[4] = 0;
      iVar1 = FUN_4092c4e8((int)puVar2,0,1);
      if (iVar1 != 0) goto LAB_409346bc;
      FUN_40934428((int)puVar2,1,uVar3,param_4);
    }
    if (param_2 != 0) {
      *(undefined4 *)(param_2 + 0x10) = 0x3003;
    }
  }
LAB_409346bc:
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 409346c4 FUN_409346c4 */

/* Boundary evidence: original MIPS .pdata 409346c4..4093480b. Semantic name remains unreviewed. */

void FUN_409346c4(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  bool bVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *in_stack_00000048;
  int in_stack_0000004c;
  
  FUN_40935a10();
  bVar1 = false;
  if (*(int *)(param_2 + 8) != 0x30a1) {
    if (in_stack_0000004c != 0) {
      *(undefined4 *)(in_stack_0000004c + 0x10) = 0x3009;
    }
    goto LAB_40934800;
  }
  uVar6 = 0x30ba;
  bVar2 = FUN_4092ad68(param_1,param_2,param_4,0x30ba);
  if ((CONCAT31(extraout_var,bVar2) == 1) || (iVar3 = FUN_4092b540(param_4), iVar3 == 1)) {
    if (in_stack_0000004c == 0) goto LAB_40934800;
    uVar6 = 0x3002;
  }
  else {
    if (in_stack_00000048 != (int *)0x0) {
      do {
        if (*in_stack_00000048 == 0x3038) {
          bVar1 = true;
        }
        else if (*in_stack_00000048 != 0x30d2) {
          if (in_stack_0000004c == 0) goto LAB_40934800;
          uVar6 = 0x300c;
          goto LAB_4093473c;
        }
        prefetch(in_stack_00000048 + 4,0);
        in_stack_00000048 = in_stack_00000048 + 2;
      } while (!bVar1);
    }
    puVar4 = FUN_4092ac7c();
    if (puVar4 != (undefined4 *)0x0) {
      puVar5 = puVar4;
      iVar3 = FUN_40927268(param_2,param_4,puVar4);
      if (iVar3 == 0x3000) {
        puVar4[1] = param_4;
        *puVar4 = param_3;
      }
      else {
        FUN_4092afc4((int)puVar4,1,puVar5,uVar6,in_stack_0000004c,param_6);
        if (in_stack_0000004c != 0) {
          *(int *)(in_stack_0000004c + 0x10) = iVar3;
        }
      }
      goto LAB_40934800;
    }
    if (in_stack_0000004c == 0) goto LAB_40934800;
    uVar6 = 0x3003;
  }
LAB_4093473c:
  *(undefined4 *)(in_stack_0000004c + 0x10) = uVar6;
LAB_40934800:
                    /* WARNING: Subroutine does not return */
  FUN_40935a40(0x18);
}



/* 4093480c FUN_4093480c */

/* Boundary evidence: original MIPS .pdata 4093480c..40934933. Semantic name remains unreviewed. */

void FUN_4093480c(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *in_stack_00000040;
  int in_stack_00000044;
  
  FUN_40935ae0();
  bVar1 = false;
  iVar4 = 0;
  if (*(int *)(param_2 + 8) == 0x30a0) {
    if (in_stack_00000040 != (int *)0x0) {
      do {
        iVar3 = *in_stack_00000040;
        if (iVar3 == 0x3038) {
          bVar1 = true;
        }
        else if (iVar3 == 0x30bc) {
          iVar4 = in_stack_00000040[1];
        }
        else if (iVar3 != 0x30d2) {
          if (in_stack_00000044 != 0) {
            *(undefined4 *)(in_stack_00000044 + 0x10) = 0x300c;
          }
          goto LAB_40934928;
        }
        prefetch(in_stack_00000040 + 4,0);
        in_stack_00000040 = in_stack_00000040 + 2;
      } while (!bVar1);
    }
    puVar2 = FUN_4092ac7c();
    if (puVar2 == (undefined4 *)0x0) {
      if (in_stack_00000044 != 0) {
        *(undefined4 *)(in_stack_00000044 + 0x10) = 0x3003;
      }
    }
    else {
      iVar3 = FUN_40927df4(param_2,param_3,param_4,iVar4,puVar2);
      if ((iVar3 != 0x3000) &&
         (FUN_4092afc4((int)puVar2,1,param_4,iVar4,puVar2,param_6), in_stack_00000044 != 0)) {
        *(int *)(in_stack_00000044 + 0x10) = iVar3;
      }
    }
  }
  else if (in_stack_00000044 != 0) {
    *(undefined4 *)(in_stack_00000044 + 0x10) = 0x3009;
  }
LAB_40934928:
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 40934934 FUN_40934934 */

/* Boundary evidence: original MIPS .pdata 40934934..40934a7f. Semantic name remains unreviewed. */

undefined4 FUN_40934934(int param_1,undefined4 param_2,HANDLE param_3,int *param_4,int param_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined4 *puVar4;
  undefined1 *pv;
  int *piVar5;
  undefined4 uVar6;
  undefined4 in_stack_ffffff80;
  undefined4 in_stack_ffffff84;
  undefined1 auStack_78 [88];
  
  pv = auStack_78;
  bVar1 = false;
  piVar5 = param_4;
  iVar3 = GetObjectW(param_3,0x54,pv);
  if ((iVar3 == 0) ||
     (iVar3 = FUN_40933ab0(param_1,param_3,pv,piVar5,in_stack_ffffff80), iVar3 == 0)) {
    if (param_5 != 0) {
      *(undefined4 *)(param_5 + 0x10) = 0x300c;
    }
  }
  else {
    uVar6 = 0x30b0;
    iVar3 = param_5;
    bVar2 = FUN_4092ad68(param_1,param_2,(int)param_3,0x30b0);
    if (CONCAT31(extraout_var,bVar2) == 1) {
      if (param_5 == 0) {
        return 0;
      }
      uVar6 = 0x3002;
    }
    else {
      if (param_4 != (int *)0x0) {
        do {
          if (*param_4 == 0x3038) {
            bVar1 = true;
          }
          else if (*param_4 != 0x30d2) {
            if (param_5 == 0) {
              return 0;
            }
            uVar6 = 0x300c;
            goto LAB_40934a54;
          }
          prefetch(param_4 + 4,0);
          param_4 = param_4 + 2;
        } while (!bVar1);
      }
      puVar4 = FUN_4092ac7c();
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[8] = 0;
        FUN_4092afc4((int)puVar4,1,param_3,uVar6,iVar3,in_stack_ffffff84);
      }
      if (param_5 == 0) {
        return 0;
      }
      uVar6 = 0x3003;
    }
LAB_40934a54:
    *(undefined4 *)(param_5 + 0x10) = uVar6;
  }
  return 0;
}



/* 40934a80 eglDestroyImageKHR */

/* Boundary evidence: original MIPS .pdata 40934a80..40934ae3. Semantic name remains unreviewed. */

void eglDestroyImageKHR(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x14a80  14  eglDestroyImageKHR */
  FUN_40935b30();
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_4092b0c4(param_1,param_2,iVar1,param_4,param_5,param_6);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 40934ae4 eglCreateImageKHR */

/* Boundary evidence: original MIPS .pdata 40934ae4..40934b5f. Semantic name remains unreviewed. */

void eglCreateImageKHR(uint param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  int *in_stack_00000040;
  
                    /* 0x14ae4  8  eglCreateImageKHR */
  FUN_40935ae0();
  piVar1 = (int *)FUN_4092c9b0();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    FUN_4092b178(param_1,param_2,param_3,param_4,in_stack_00000040,piVar1);
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 40934b60 eglGetProcAddress */

/* Boundary evidence: original MIPS .pdata 40934b60..40934bcb. Semantic name remains unreviewed. */

undefined * eglGetProcAddress(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  
                    /* 0x14b60  23  eglGetProcAddress */
  puVar3 = (undefined *)0x0;
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    puVar3 = FUN_40930978(param_1,iVar1);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return puVar3;
}



/* 40934bcc eglReleaseThread */

/* Boundary evidence: original MIPS .pdata 40934bcc..40934c23. Semantic name remains unreviewed. */

undefined4 eglReleaseThread(void)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x14bcc  31  eglReleaseThread */
  piVar1 = FUN_409319b8();
  if (piVar1 != (int *)0x0) {
    mali_sys_lock_lock(piVar1[5]);
  }
  uVar2 = FUN_4092c8ac();
  piVar1 = FUN_409319b8();
  if (piVar1 != (int *)0x0) {
    mali_sys_lock_unlock(piVar1[5]);
  }
  return uVar2;
}



/* 40934c24 eglGetCurrentSurface */

/* Boundary evidence: original MIPS .pdata 40934c24..40934c8f. Semantic name remains unreviewed. */

uint eglGetCurrentSurface(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  
                    /* 0x14c24  20  eglGetCurrentSurface */
  uVar3 = 0;
  puVar1 = (undefined4 *)FUN_4092c9b0();
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[4] = 0x3000;
    uVar3 = FUN_4092d83c(param_1,puVar1);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 40934c90 eglSurfaceAttrib */

/* Boundary evidence: original MIPS .pdata 40934c90..40934d03. Semantic name remains unreviewed. */

void eglSurfaceAttrib(uint param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x14c90  32  eglSurfaceAttrib */
  FUN_40935ae0();
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_4092d1e0(param_1,param_2,param_3,param_4,iVar1);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 40934d04 eglQuerySurface */

/* Boundary evidence: original MIPS .pdata 40934d04..40934d77. Semantic name remains unreviewed. */

void eglQuerySurface(uint param_1,uint param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x14d04  29  eglQuerySurface */
  FUN_40935ae0();
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_4092d3dc(param_1,param_2,param_3,param_4,iVar1);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 40934d78 eglDestroySurface */

/* Boundary evidence: original MIPS .pdata 40934d78..40934ddb. Semantic name remains unreviewed. */

void eglDestroySurface(uint param_1,uint param_2)

{
  int *piVar1;
  
                    /* 0x14d78  15  eglDestroySurface */
  FUN_40935b30();
  piVar1 = (int *)FUN_4092c9b0();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    FUN_4092dd14(param_1,param_2,piVar1);
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 40934ddc eglCreatePixmapSurface */

/* Boundary evidence: original MIPS .pdata 40934ddc..40934e4f. Semantic name remains unreviewed. */

void eglCreatePixmapSurface(uint param_1,uint param_2,HANDLE param_3,undefined4 param_4)

{
  int *piVar1;
  
                    /* 0x14ddc  11  eglCreatePixmapSurface */
  FUN_40935ae0();
  piVar1 = (int *)FUN_4092c9b0();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    FUN_4092ddf8(param_1,param_2,param_3,param_4,piVar1);
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 40934e50 eglCreatePbufferFromClientBuffer */

/* Boundary evidence: original MIPS .pdata 40934e50..40934ecb. Semantic name remains unreviewed. */

void eglCreatePbufferFromClientBuffer(uint param_1,int param_2,int param_3,uint param_4)

{
  int *piVar1;
  int *in_stack_00000040;
  
                    /* 0x14e50  9  eglCreatePbufferFromClientBuffer */
  FUN_40935ae0();
  piVar1 = (int *)FUN_4092c9b0();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    FUN_4092dff4(param_1,param_2,param_3,param_4,in_stack_00000040,piVar1);
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 40934ecc eglCreatePbufferSurface */

/* Boundary evidence: original MIPS .pdata 40934ecc..40934f57. Semantic name remains unreviewed. */

undefined4 eglCreatePbufferSurface(uint param_1,uint param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x14ecc  10  eglCreatePbufferSurface */
  uVar2 = 0;
  piVar1 = (int *)FUN_4092c9b0();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    uVar2 = FUN_4092e184(param_1,param_2,param_3,piVar1);
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
  return uVar2;
}



/* 40934f58 eglCreateWindowSurface */

/* Boundary evidence: original MIPS .pdata 40934f58..40934fcb. Semantic name remains unreviewed. */

void eglCreateWindowSurface(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
                    /* 0x14f58  12  eglCreateWindowSurface */
  FUN_40935ae0();
  piVar1 = (int *)FUN_4092c9b0();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    FUN_4092e2dc(param_1,param_2,param_3,param_4,piVar1);
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 40934fcc eglTerminate */

/* Boundary evidence: original MIPS .pdata 40934fcc..40935037. Semantic name remains unreviewed. */

undefined4 eglTerminate(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x14fcc  35  eglTerminate */
  uVar2 = 0;
  piVar1 = (int *)FUN_4092c9b0();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    uVar2 = FUN_409344f0(param_1,piVar1,param_3,param_4);
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
  return uVar2;
}



/* 40935038 eglInitialize */

/* Boundary evidence: original MIPS .pdata 40935038..409350c3. Semantic name remains unreviewed. */

undefined4 eglInitialize(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x15038  24  eglInitialize */
  uVar3 = 0;
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    uVar3 = FUN_4093429c(param_1,param_2,param_3,iVar1);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 409350c4 eglGetCurrentDisplay */

/* Boundary evidence: original MIPS .pdata 409350c4..4093511f. Semantic name remains unreviewed. */

undefined4 eglGetCurrentDisplay(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x150c4  19  eglGetCurrentDisplay */
  uVar3 = 0;
  puVar1 = (undefined4 *)FUN_4092c9b0();
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[4] = 0x3000;
    uVar3 = FUN_40934234(puVar1);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 40935120 eglGetDisplay */

/* Boundary evidence: original MIPS .pdata 40935120..4093518b. Semantic name remains unreviewed. */

undefined4 eglGetDisplay(HDC param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x15120  21  eglGetDisplay */
  uVar3 = 0;
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    uVar3 = FUN_40934608(param_1,iVar1,param_3,param_4);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 4093518c eglGetCurrentContext */

/* Boundary evidence: original MIPS .pdata 4093518c..409351e7. Semantic name remains unreviewed. */

uint eglGetCurrentContext(void)

{
  int *piVar1;
  uint uVar2;
  
                    /* 0x1518c  18  eglGetCurrentContext */
  uVar2 = 0;
  piVar1 = (int *)FUN_4092c9b0();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    uVar2 = FUN_409323dc(piVar1);
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
  return uVar2;
}



/* 409351e8 eglMakeCurrent */

/* Boundary evidence: original MIPS .pdata 409351e8..4093525b. Semantic name remains unreviewed. */

void eglMakeCurrent(uint param_1,uint param_2,int *param_3,uint param_4,undefined4 param_5,
                   int param_6)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x151e8  25  eglMakeCurrent */
  FUN_40935ae0();
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_409329a4(param_1,param_2,param_3,param_4,iVar1,param_6);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 4093525c eglQueryContext */

/* Boundary evidence: original MIPS .pdata 4093525c..409352cf. Semantic name remains unreviewed. */

void eglQueryContext(uint param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x1525c  27  eglQueryContext */
  FUN_40935ae0();
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_40932234(param_1,param_2,param_3,param_4,iVar1);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 409352d0 eglDestroyContext */

/* Boundary evidence: original MIPS .pdata 409352d0..40935333. Semantic name remains unreviewed. */

void eglDestroyContext(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x152d0  13  eglDestroyContext */
  FUN_40935b30();
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_409326e4(param_1,param_2,iVar1,param_4);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 40935334 eglCreateContext */

/* Boundary evidence: original MIPS .pdata 40935334..409353a7. Semantic name remains unreviewed. */

void eglCreateContext(uint param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x15334  7  eglCreateContext */
  FUN_40935ae0();
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_409327c4(param_1,param_2,param_3,param_4,iVar1);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 409353a8 eglQueryAPI */

/* Boundary evidence: original MIPS .pdata 409353a8..409353fb. Semantic name remains unreviewed. */

undefined4 eglQueryAPI(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x153a8  26  eglQueryAPI */
  uVar3 = 0x3038;
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    uVar3 = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 409353fc eglBindAPI */

/* Boundary evidence: original MIPS .pdata 409353fc..40935467. Semantic name remains unreviewed. */

undefined4 eglBindAPI(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x153fc  3  eglBindAPI */
  uVar2 = 0;
  piVar1 = (int *)FUN_4092c9b0();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    uVar2 = FUN_40932150(param_1,piVar1);
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
  return uVar2;
}



/* 40935468 eglReleaseTexImage */

/* Boundary evidence: original MIPS .pdata 40935468..409354f3. Semantic name remains unreviewed. */

undefined4 eglReleaseTexImage(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x15468  30  eglReleaseTexImage */
  uVar3 = 0;
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    uVar3 = FUN_40930a74(param_1,param_2,param_3,iVar1);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 409354f4 eglBindTexImage */

/* Boundary evidence: original MIPS .pdata 409354f4..4093557f. Semantic name remains unreviewed. */

undefined4 eglBindTexImage(uint param_1,uint param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x154f4  4  eglBindTexImage */
  uVar2 = 0;
  piVar1 = (int *)FUN_4092c9b0();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    uVar2 = FUN_409314b0(param_1,param_2,param_3,piVar1);
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
  return uVar2;
}



/* 40935580 eglSwapInterval */

/* Boundary evidence: original MIPS .pdata 40935580..409355e3. Semantic name remains unreviewed. */

void eglSwapInterval(uint param_1,int param_2)

{
  int *piVar1;
  
                    /* 0x15580  34  eglSwapInterval */
  FUN_40935b30();
  piVar1 = (int *)FUN_4092c9b0();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    FUN_40930c14(param_1,param_2,piVar1);
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 409355e4 eglCopyBuffers */

/* Boundary evidence: original MIPS .pdata 409355e4..4093566f. Semantic name remains unreviewed. */

undefined4 eglCopyBuffers(uint param_1,uint param_2,HANDLE param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int unaff_s1;
  undefined4 unaff_s2;
  undefined4 unaff_s3;
  
                    /* 0x155e4  6  eglCopyBuffers */
  uVar3 = 0;
  puVar1 = (undefined4 *)FUN_4092c9b0();
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[4] = 0x3000;
    uVar3 = FUN_40930d18(param_1,param_2,param_3,puVar1,unaff_s3,unaff_s2,unaff_s1);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 40935670 eglSwapBuffers */

/* Boundary evidence: original MIPS .pdata 40935670..409356d3. Semantic name remains unreviewed. */

void eglSwapBuffers(uint param_1,uint param_2)

{
  int *piVar1;
  
                    /* 0x15670  33  eglSwapBuffers */
  FUN_40935b30();
  piVar1 = (int *)FUN_4092c9b0();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    FUN_40930ed4(param_1,param_2,piVar1);
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 409356d4 eglWaitNative */

/* Boundary evidence: original MIPS .pdata 409356d4..4093573f. Semantic name remains unreviewed. */

undefined4 eglWaitNative(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x156d4  38  eglWaitNative */
  uVar2 = 0;
  piVar1 = (int *)FUN_4092c9b0();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    uVar2 = FUN_409310a4(param_1,piVar1);
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
  return uVar2;
}



/* 40935740 eglWaitGL */

/* Boundary evidence: original MIPS .pdata 40935740..4093579b. Semantic name remains unreviewed. */

undefined4 eglWaitGL(void)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x15740  37  eglWaitGL */
  uVar2 = 0;
  piVar1 = (int *)FUN_4092c9b0();
  if (piVar1 != (int *)0x0) {
    piVar1[4] = 0x3000;
    uVar2 = FUN_40931420(piVar1);
    piVar1 = FUN_409319b8();
    if (piVar1 != (int *)0x0) {
      mali_sys_lock_unlock(piVar1[5]);
    }
  }
  return uVar2;
}



/* 4093579c eglWaitClient */

/* Boundary evidence: original MIPS .pdata 4093579c..409357f7. Semantic name remains unreviewed. */

undefined4 eglWaitClient(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x1579c  36  eglWaitClient */
  uVar3 = 0;
  puVar1 = (undefined4 *)FUN_4092c9b0();
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[4] = 0x3000;
    uVar3 = FUN_409311dc(puVar1);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 409357f8 eglQueryString */

/* Boundary evidence: original MIPS .pdata 409357f8..4093585f. Semantic name remains unreviewed. */

void eglQueryString(uint param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x157f8  28  eglQueryString */
  FUN_40935b30();
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_4093128c(param_1,param_2,iVar1);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b50(0x10);
}



/* 40935860 eglGetError */

/* Boundary evidence: original MIPS .pdata 40935860..409358ab. Semantic name remains unreviewed. */

undefined4 eglGetError(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
                    /* 0x15860  22  eglGetError */
  uVar3 = 0x3000;
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    uVar3 = *(undefined4 *)(iVar1 + 0x10);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
  return uVar3;
}



/* 409358ac eglGetConfigAttrib */

/* Boundary evidence: original MIPS .pdata 409358ac..4093591f. Semantic name remains unreviewed. */

void eglGetConfigAttrib(uint param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x158ac  16  eglGetConfigAttrib */
  FUN_40935ae0();
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_40933718(param_1,param_2,param_3,param_4,iVar1);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 40935920 eglChooseConfig */

/* Boundary evidence: original MIPS .pdata 40935920..4093599b. Semantic name remains unreviewed. */

void eglChooseConfig(uint param_1,undefined4 *param_2,uint *param_3,uint param_4,undefined4 param_5,
                    undefined4 param_6,int param_7,HANDLE param_8,uint *param_9,undefined4 param_10,
                    int param_11,int param_12,int param_13,int param_14,uint param_15,uint *param_16
                    ,undefined4 param_17,int param_18,int param_19,int param_20,int param_21,
                    int param_22,int param_23,int param_24,int param_25,int param_26,int param_27,
                    int param_28,uint param_29,int param_30,int param_31)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x15920  5  eglChooseConfig */
  FUN_40935ae0();
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_40933b28(param_1,param_2,param_3,param_4,param_17,iVar1,param_7,param_8,param_9,param_10,
                 param_11,param_12,param_13,param_14,param_15,param_16,param_17,param_18,param_19,
                 param_20,param_21,param_22,param_23,param_24,param_25,param_26,param_27,param_28,
                 param_29,param_30,param_31);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 4093599c eglGetConfigs */

/* Boundary evidence: original MIPS .pdata 4093599c..40935a0f. Semantic name remains unreviewed. */

void eglGetConfigs(uint param_1,uint *param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x1599c  17  eglGetConfigs */
  FUN_40935ae0();
  iVar1 = FUN_4092c9b0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0x3000;
    FUN_409339b4(param_1,param_2,param_3,param_4,iVar1);
    piVar2 = FUN_409319b8();
    if (piVar2 != (int *)0x0) {
      mali_sys_lock_unlock(piVar2[5]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40935b08(0x18);
}



/* 40935a10 FUN_40935a10 */

/* Boundary evidence: original MIPS .pdata 40935a10..40935a3f. Semantic name remains unreviewed. */

void FUN_40935a10(void)

{
  return;
}



/* 40935a40 FUN_40935a40 */

/* Boundary evidence: original MIPS .pdata 40935a40..40935a6f. Semantic name remains unreviewed. */

void FUN_40935a40(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x40935a68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&stack0x0000001c + param_1))();
  return;
}



/* 40935a70 FUN_40935a70 */

/* Boundary evidence: original MIPS .pdata 40935a70..40935aa7. Semantic name remains unreviewed. */

void FUN_40935a70(void)

{
  return;
}



/* 40935aa8 FUN_40935aa8 */

/* Boundary evidence: original MIPS .pdata 40935aa8..40935adf. Semantic name remains unreviewed. */

void FUN_40935aa8(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x40935ad8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&stack0x00000024 + param_1))();
  return;
}



/* 40935ae0 FUN_40935ae0 */

/* Boundary evidence: original MIPS .pdata 40935ae0..40935b07. Semantic name remains unreviewed. */

void FUN_40935ae0(void)

{
  return;
}



/* 40935b08 FUN_40935b08 */

/* Boundary evidence: original MIPS .pdata 40935b08..40935b2f. Semantic name remains unreviewed. */

void FUN_40935b08(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x40935b28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&stack0x00000014 + param_1))();
  return;
}



/* 40935b30 FUN_40935b30 */

/* Boundary evidence: original MIPS .pdata 40935b30..40935b4f. Semantic name remains unreviewed. */

void FUN_40935b30(void)

{
  return;
}



/* 40935b50 FUN_40935b50 */

/* Boundary evidence: original MIPS .pdata 40935b50..40935b6f. Semantic name remains unreviewed. */

void FUN_40935b50(int param_1)

{
  undefined4 uStackX_c;
  
                    /* WARNING: Could not recover jumptable at 0x40935b68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)&uStackX_c + param_1))();
  return;
}



/* 40935b70 FUN_40935b70 */

/* Boundary evidence: original MIPS .pdata 40935b70..40935bc3. Semantic name remains unreviewed. */

void FUN_40935b70(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40925f80(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40935bc4 FUN_40935bc4 */

/* Boundary evidence: original MIPS .pdata 40935bc4..40935bef. Semantic name remains unreviewed. */

undefined4 FUN_40935bc4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40935b70(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}


