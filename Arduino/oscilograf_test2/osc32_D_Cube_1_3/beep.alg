#   Algorithm Builder `   d   K   K   K   K   d   K   K   K   d   K   K   K   K   K   d   K   K   d   K   K   d   K   K   U          beeptime  int24                                                         ~  Y                    V      &       	 . beep2    F              30 -> x   L     '          F!              1 -> portd3  ! F#               wait_mks(400)  # F!              0 -> portd3  ! F#               wait_mks(400)  # C    0      ��
              
       
       
       
       
              
       
       
       
       
              
       
       
       
       
       
       
       
       
       
              
       
       
       
       
       
       dth x--  F         	     ret   V#     6  
       beep ���� # F!              1 -> ddrd.3  ! C"    1      � r  TRadioButtonJMPVectorRadioButtonLeftTophWidth� HeightCursorcrHandPointCaption
JMP VectorTabOrder  TRadioButtonAllElementsRadioButtonLeftTop� Width� HeightCursorcrHandPointCaptionAll elementsChecked	TabOrder beeprg=0  "C#    2       �r  TRadioButtonJMPVectorRadioButtonLeftTophWidth� HeightCursorcrHandPointCaption
JMP VectorTabOrder  TRadioButtonAllElementsRadioButtonLeftTop� Width� HeightCursorcrHandPointCaptionAll elementsChecked	TabOrder beeprg-=1  #F              beep_a   L     7          C#    3       �r  TRadioButtonJMPVectorRadioButtonLeftTophWidth� HeightCursorcrHandPointCaption
JMP VectorTabOrder  TRadioButtonAllElementsRadioButtonLeftTop� Width� HeightCursorcrHandPointCaptionAll elementsChecked	TabOrder beeprg-=2  #F              beep_b   L     8          C#    4       �r  TRadioButtonJMPVectorRadioButtonLeftTophWidth� HeightCursorcrHandPointCaption
JMP VectorTabOrder  TRadioButtonAllElementsRadioButtonLeftTop� Width� HeightCursorcrHandPointCaptionAll elementsChecked	TabOrder beeprg-=3  #F              beep_c   L     9          C#    5       �r  TRadioButtonJMPVectorRadioButtonLeftTophWidth� HeightCursorcrHandPointCaption
JMP VectorTabOrder  TRadioButtonAllElementsRadioButtonLeftTop� Width� HeightCursorcrHandPointCaptionAll elementsChecked	TabOrder beeprg-=4  #F              beep_b   F              beep_c   L     :          C#    6       �r  TRadioButtonJMPVectorRadioButtonLeftTophWidth� HeightCursorcrHandPointCaption
JMP VectorTabOrder  TRadioButtonAllElementsRadioButtonLeftTop� Width� HeightCursorcrHandPointCaptionAll elementsChecked	TabOrder beeprg-=5  #F              beep_c   F              beep_b   L     ;          C#    7       �r  TRadioButtonJMPVectorRadioButtonLeftTophWidth� HeightCursorcrHandPointCaption
JMP VectorTabOrder  TRadioButtonAllElementsRadioButtonLeftTop� Width� HeightCursorcrHandPointCaptionAll elementsChecked	TabOrder beeprg-=6  #F              beep_d   F               beep_e   L     <  !        C#    8  "     �r  TRadioButtonJMPVectorRadioButtonLeftTophWidth� HeightCursorcrHandPointCaption
JMP VectorTabOrder  TRadioButtonAllElementsRadioButtonLeftTop� Width� HeightCursorcrHandPointCaptionAll elementsChecked	TabOrder beeprg-=7  #F         #     beep_e   F         $     beep_d   L     =  %        C#    9  &     �r  TRadioButtonJMPVectorRadioButtonLeftTophWidth� HeightCursorcrHandPointCaption
JMP VectorTabOrder  TRadioButtonAllElementsRadioButtonLeftTop� Width� HeightCursorcrHandPointCaptionAll elementsChecked	TabOrder beeprg-=8  #F         '     beep_e   F         (     beep_d   F         )     beep_e   F         *     beep_d   L     >  +        L     ?  ,        F!         -     0 -> ddrd.3  ! C5       .    #�                                                                                                                                                                                                                                                             offtime=1000 ���� ���������� 5F4         /     setlight �������������� ������� 4 L     @  0        FJ         1     wait_ms(5) �������� ��� ��������� ���������� �� ch_ok J F         2     ret   V!     B  3     	 ! beep_a  ! F         4     30 -> x   L     C  5        F!         6     1 -> portd3  ! F#         7      wait_mks(200)  # F!         8     0 -> portd3  ! F#         9      wait_mks(200)  # C    =  :    ��
              
       
       
       
       
              
       
       
       
       
              
       
       
       
       
       
       
       
       
       
              
       
       
       
       
       
       dth x--  F         ;     ret   V!     R  <      ! beep_b  ! F         =     30 -> x   L     S  >        F!         ?     1 -> portd3  ! F#         @      wait_mks(100)  # F!         A     0 -> portd3  ! F#         B      wait_mks(100)  # C    @  C    ��
              
       
       
       
       
              
       
       
       
       
              
       
       
       
       
       
       
       
       
       
              
       
       
       
       
       
       dth x--  F         D     ret   V!     b  E      . beep_c  ! F         F     30 -> x   L     c  G        F!         H     1 -> portd3  ! F#         I      wait_mks(150)  # F!         J     0 -> portd3  ! F#         K      wait_mks(150)  # C    C  L    ��
              
       
       
       
       
              
       
       
       
       
              
       
       
       
       
       
       
       
       
       
              
       
       
       
       
       
       dth x--  F         M     ret   V!     p  N      ! beep_d  ! F         O     80 -> x   L     q  P        F!         Q     1 -> portd3  ! F#         R      wait_mks(200)  # F!         S     0 -> portd3  ! F#         T      wait_mks(200)  # C    F  U    ��
              
       
       
       
       
              
       
       
       
       
              
       
       
       
       
       
       
       
       
       
              
       
       
       
       
       
       dth x--  F         V     ret   V!     �  W      . beep_e  ! F         X     60 -> x   L     �  Y        F!         Z     1 -> portd3  ! F#         [      wait_mks(250)  # F!         \     0 -> portd3  ! F#         ]      wait_mks(250)  # C    I  ^    ��
              
       
       
       
       
              
       
       
       
       
              
       
       
       
       
       
       
       
       
       
              
       
       
       
       
       
       dth x--  F         _     ret       